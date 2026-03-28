import os
import subprocess
import tempfile
import tkinter as tk
from tkinter import filedialog, messagebox, font as tkfont

ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EXECUTABLE = os.path.join(ROOT_DIR, "rust_parser.exe")

# ── Palette ───────────────────────────────────────────────────────────────────
BG        = "#0e0e0f"
BG2       = "#161618"
BG3       = "#1e1e21"
BORDER    = "#2a2a2e"
ACCENT    = "#e8773a"       # warm orange — Rust's color
ACCENT_DIM= "#7a3d1c"
FG        = "#d4d0c8"
FG_DIM    = "#606060"
FG_CODE   = "#c9c4bc"
GREEN     = "#6db86d"
RED       = "#c05050"

class IconButton(tk.Canvas):
    """Flat minimal button with hover state."""
    def __init__(self, parent, text, icon="", command=None, accent=False, **kw):
        super().__init__(parent, bd=0, highlightthickness=0,
                         cursor="hand2", **kw)
        self._text    = f"{icon}  {text}" if icon else text
        self._cmd     = command
        self._accent  = accent
        self._normal  = ACCENT if accent else BG3
        self._hover   = "#f08840" if accent else "#272729"
        self._fg      = "#0e0e0f" if accent else FG
        self.config(bg=BG)
        self.bind("<Configure>", self._draw)
        self.bind("<Enter>",     lambda e: self._set(self._hover))
        self.bind("<Leave>",     lambda e: self._set(self._normal))
        self.bind("<Button-1>",  lambda e: command() if command else None)

    def _draw(self, e=None):
        w, h = self.winfo_width(), self.winfo_height()
        self.delete("all")
        r = 4
        self._rect = self._rounded(0, 0, w, h, r, self._normal)
        self.create_text(w//2, h//2, text=self._text,
                         fill=self._fg, font=("Segoe UI", 9))

    def _set(self, color):
        w, h = self.winfo_width(), self.winfo_height()
        self.delete("all")
        self._rounded(0, 0, w, h, 4, color)
        self.create_text(w//2, h//2, text=self._text,
                         fill=self._fg, font=("Segoe UI", 9))

    def _rounded(self, x1, y1, x2, y2, r, fill):
        return self.create_polygon(
            x1+r, y1,   x2-r, y1,
            x2,   y1,   x2,   y1+r,
            x2,   y2-r, x2,   y2,
            x2-r, y2,   x1+r, y2,
            x1,   y2,   x1,   y2-r,
            x1,   y1+r, x1,   y1,
            smooth=True, fill=fill, outline=""
        )


class App:
    def __init__(self, root):
        self.root = root
        self.root.title("rust_parser")
        self.root.geometry("1280x800")
        self.root.configure(bg=BG)
        self.root.minsize(900, 600)

        self._build_ui()
        self._load_example()

    # ── Layout ────────────────────────────────────────────────────────────────
    def _build_ui(self):
        # ── Top bar ──────────────────────────────────────────────────────────
        bar = tk.Frame(self.root, bg=BG2, height=48)
        bar.pack(fill=tk.X)
        bar.pack_propagate(False)

        # Logo / title
        title_frame = tk.Frame(bar, bg=BG2)
        title_frame.pack(side=tk.LEFT, padx=16)
        tk.Label(title_frame, text="⬡", fg=ACCENT, bg=BG2,
                 font=("Segoe UI", 16)).pack(side=tk.LEFT, padx=(0,6))
        tk.Label(title_frame, text="rust_parser", fg=FG, bg=BG2,
                 font=("Segoe UI", 11, "bold")).pack(side=tk.LEFT)
        tk.Label(title_frame, text="lexer · parser · ast", fg=FG_DIM, bg=BG2,
                 font=("Segoe UI", 8)).pack(side=tk.LEFT, padx=8)

        # Separator line under bar
        tk.Frame(self.root, bg=BORDER, height=1).pack(fill=tk.X)

        # ── Toolbar ──────────────────────────────────────────────────────────
        toolbar = tk.Frame(self.root, bg=BG, pady=10)
        toolbar.pack(fill=tk.X, padx=16)

        btn_cfg = dict(height=28)

        b_open = IconButton(toolbar, "Open file", "📂",
                            command=self.open_file, **btn_cfg)
        b_open.pack(side=tk.LEFT, ipadx=10, padx=(0,6))
        b_open.config(width=100)

        tk.Frame(toolbar, bg=BORDER, width=1).pack(
            side=tk.LEFT, fill=tk.Y, padx=8)

        b_all = IconButton(toolbar, "All", "▶",
                           command=lambda: self.run_mode("--all"),
                           accent=True, **btn_cfg)
        b_all.pack(side=tk.LEFT, ipadx=10, padx=(0,6))
        b_all.config(width=80)

        b_tok = IconButton(toolbar, "Tokens", "⬡",
                           command=lambda: self.run_mode("--tokens"), **btn_cfg)
        b_tok.pack(side=tk.LEFT, ipadx=10, padx=(0,6))
        b_tok.config(width=90)

        b_ast = IconButton(toolbar, "AST", "⌥",
                           command=lambda: self.run_mode("--ast"), **btn_cfg)
        b_ast.pack(side=tk.LEFT, ipadx=10, padx=(0,6))
        b_ast.config(width=80)

        tk.Frame(toolbar, bg=BORDER, width=1).pack(
            side=tk.LEFT, fill=tk.Y, padx=8)

        b_clr = IconButton(toolbar, "Clear", "✕",
                           command=self.clear_all, **btn_cfg)
        b_clr.pack(side=tk.LEFT, ipadx=10)
        b_clr.config(width=80)

        # Status dot (right side)
        self.status_var = tk.StringVar(value="ready")
        self.status_dot = tk.Label(toolbar, text="●", fg=GREEN, bg=BG,
                                   font=("Segoe UI", 10))
        self.status_dot.pack(side=tk.RIGHT, padx=(0,4))
        self.status_lbl = tk.Label(toolbar, textvariable=self.status_var,
                                   fg=FG_DIM, bg=BG, font=("Segoe UI", 9))
        self.status_lbl.pack(side=tk.RIGHT)

        tk.Frame(self.root, bg=BORDER, height=1).pack(fill=tk.X)

        # ── Main split pane ───────────────────────────────────────────────────
        pane = tk.PanedWindow(self.root, orient=tk.HORIZONTAL,
                              bg=BORDER, sashwidth=3,
                              sashrelief=tk.FLAT, bd=0)
        pane.pack(fill=tk.BOTH, expand=True)

        # Left: code editor
        left = tk.Frame(pane, bg=BG2)
        pane.add(left, minsize=300)

        self._panel_header(left, "SOURCE", ".rs")

        code_wrap = tk.Frame(left, bg=BG2)
        code_wrap.pack(fill=tk.BOTH, expand=True)

        # Line numbers
        self.line_nums = tk.Text(code_wrap, width=4, state=tk.DISABLED,
                                 bg=BG2, fg=FG_DIM, bd=0,
                                 font=("Cascadia Code", 11),
                                 padx=6, pady=8, selectbackground=BG2,
                                 highlightthickness=0, relief=tk.FLAT)
        self.line_nums.pack(side=tk.LEFT, fill=tk.Y)

        tk.Frame(code_wrap, bg=BORDER, width=1).pack(side=tk.LEFT, fill=tk.Y)

        self.code_text = tk.Text(code_wrap, wrap="none",
                                 font=("Cascadia Code", 11),
                                 bg=BG2, fg=FG_CODE, bd=0,
                                 insertbackground=ACCENT,
                                 selectbackground=ACCENT_DIM,
                                 pady=8, padx=12,
                                 highlightthickness=0, relief=tk.FLAT,
                                 undo=True)
        self.code_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        code_sb = tk.Scrollbar(code_wrap, command=self.code_text.yview,
                               bg=BG3, troughcolor=BG2, bd=0,
                               highlightthickness=0, width=8)
        code_sb.pack(side=tk.RIGHT, fill=tk.Y)
        self.code_text.config(yscrollcommand=self._sync_scroll(code_sb))
        self.code_text.bind("<KeyRelease>", self._update_lines)
        self.code_text.bind("<MouseWheel>", self._update_lines)

        # Right: output
        right = tk.Frame(pane, bg=BG)
        pane.add(right, minsize=300)

        self._panel_header(right, "OUTPUT", "")

        out_wrap = tk.Frame(right, bg=BG)
        out_wrap.pack(fill=tk.BOTH, expand=True)

        self.output_text = tk.Text(out_wrap, wrap="none",
                                   font=("Cascadia Code", 10),
                                   bg=BG, fg=FG, bd=0,
                                   selectbackground=ACCENT_DIM,
                                   pady=8, padx=12,
                                   highlightthickness=0, relief=tk.FLAT,
                                   state=tk.DISABLED)
        self.output_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        out_sb = tk.Scrollbar(out_wrap, command=self.output_text.yview,
                              bg=BG3, troughcolor=BG, bd=0,
                              highlightthickness=0, width=8)
        out_sb.pack(side=tk.RIGHT, fill=tk.Y)
        self.output_text.config(yscrollcommand=out_sb.set)

        # Tag colors for output
        self.output_text.tag_config("err",  foreground=RED)
        self.output_text.tag_config("ok",   foreground=GREEN)
        self.output_text.tag_config("head", foreground=ACCENT,
                                    font=("Cascadia Code", 10, "bold"))

        # ── Status bar ────────────────────────────────────────────────────────
        tk.Frame(self.root, bg=BORDER, height=1).pack(fill=tk.X)
        sbar = tk.Frame(self.root, bg=BG2, height=24)
        sbar.pack(fill=tk.X)
        sbar.pack_propagate(False)
        self.info_lbl = tk.Label(sbar, text=f"exe → {EXECUTABLE}",
                                 fg=FG_DIM, bg=BG2, font=("Segoe UI", 8))
        self.info_lbl.pack(side=tk.LEFT, padx=12)

        self._update_lines()

    # ── Helpers ───────────────────────────────────────────────────────────────
    def _panel_header(self, parent, title, badge):
        h = tk.Frame(parent, bg=BG3, height=32)
        h.pack(fill=tk.X)
        h.pack_propagate(False)
        tk.Label(h, text=title, fg=FG_DIM, bg=BG3,
                 font=("Segoe UI", 8, "bold")).pack(side=tk.LEFT, padx=12)
        if badge:
            tk.Label(h, text=badge, fg=ACCENT, bg=BG3,
                     font=("Segoe UI", 8)).pack(side=tk.LEFT)
        tk.Frame(parent, bg=BORDER, height=1).pack(fill=tk.X)

    def _sync_scroll(self, scrollbar):
        def handler(*args):
            scrollbar.set(*args)
            self._update_lines()
        return handler

    def _update_lines(self, event=None):
        self.line_nums.config(state=tk.NORMAL)
        self.line_nums.delete("1.0", tk.END)
        lines = int(self.code_text.index(tk.END).split(".")[0]) - 1
        nums  = "\n".join(str(i) for i in range(1, lines + 1))
        self.line_nums.insert("1.0", nums)
        self.line_nums.config(state=tk.DISABLED)
        # Sync scroll position
        self.line_nums.yview_moveto(self.code_text.yview()[0])

    def _set_status(self, text, color=FG_DIM):
        self.status_var.set(text)
        self.status_dot.config(fg=color)

    def _write_output(self, text, tag=None):
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        if tag:
            self.output_text.insert(tk.END, text, tag)
        else:
            self._colorize_output(text)
        self.output_text.config(state=tk.DISABLED)

    def _colorize_output(self, text):
        """Simple colorization: lines starting with [stderr] or 'error' in red."""
        for line in text.splitlines(keepends=True):
            lo = line.lower()
            if lo.startswith("[stderr]") or "error" in lo:
                self.output_text.insert(tk.END, line, "err")
            elif lo.startswith("─") or lo.startswith("=") or lo.startswith("tokens") or lo.startswith("ast"):
                self.output_text.insert(tk.END, line, "head")
            else:
                self.output_text.insert(tk.END, line)

    # ── Actions ───────────────────────────────────────────────────────────────
    def _load_example(self):
        example = (
            "fn suma(a: i32, b: i32) -> i32 {\n"
            "    return a + b;\n"
            "}\n\n"
            "fn main() {\n"
            "    let x = 10;\n"
            "    let y = 20;\n\n"
            "    if x < y {\n"
            "        let resultado = suma(x, y);\n"
            "    } else {\n"
            "        return;\n"
            "    }\n"
            "}\n"
        )
        self.code_text.insert("1.0", example)
        self._update_lines()

    def clear_all(self):
        self.code_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.DISABLED)
        self._update_lines()
        self._set_status("ready", GREEN)

    def open_file(self):
        path = filedialog.askopenfilename(
            title="Open Rust file",
            filetypes=[("Rust files", "*.rs"), ("All files", "*.*")]
        )
        if not path:
            return
        try:
            with open(path, "r", encoding="utf-8") as f:
                content = f.read()
            self.code_text.delete("1.0", tk.END)
            self.code_text.insert("1.0", content)
            self._update_lines()
            self._set_status(os.path.basename(path), FG_DIM)
        except Exception as exc:
            messagebox.showerror("Error", str(exc))

    def run_mode(self, mode):
        if not os.path.exists(EXECUTABLE):
            messagebox.showerror(
                "Executable not found",
                f"{EXECUTABLE}\n\nCompile first with:  make"
            )
            return

        code = self.code_text.get("1.0", tk.END).strip()
        if not code:
            messagebox.showwarning("Empty", "Write or open a .rs file first.")
            return

        label = {"--all": "all", "--tokens": "tokens", "--ast": "ast"}.get(mode, mode)
        self._set_status(f"running {label}…", ACCENT)
        self.root.update_idletasks()

        temp_path = None
        try:
            with tempfile.NamedTemporaryFile("w", suffix=".rs",
                                             delete=False, encoding="utf-8") as tmp:
                tmp.write(code)
                temp_path = tmp.name

            result = subprocess.run(
                [EXECUTABLE, mode, temp_path],
                capture_output=True, text=True, cwd=ROOT_DIR
            )

            combined = result.stdout
            if result.stderr:
                combined += "\n[stderr]\n" + result.stderr

            self._write_output(combined)
            ok = result.returncode == 0
            self._set_status("done" if ok else f"exit {result.returncode}",
                             GREEN if ok else RED)

        except Exception as exc:
            messagebox.showerror("Error", str(exc))
            self._set_status("error", RED)
        finally:
            if temp_path and os.path.exists(temp_path):
                os.remove(temp_path)


if __name__ == "__main__":
    root = tk.Tk()
    try:
        root.tk.call("tk", "scaling", 1.25)
    except Exception:
        pass
    App(root)
    root.mainloop()
