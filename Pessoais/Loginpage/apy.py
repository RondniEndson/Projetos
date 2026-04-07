import customtkinter as ctk

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue") 

class LoginApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.title("Sistema de Login")
        self.geometry("400x450")
        
        self.resizable(True, True)
        self.minsize(400, 450)

        self.main_frame = ctk.CTkFrame(self, fg_color="transparent")
        self.main_frame.place(relx=0.5, rely=0.5, anchor="center")

        self.label_titulo = ctk.CTkLabel(
            self.main_frame, 
            text="Bem-vindo", 
            font=("Arial", 24, "bold")
        )
        self.label_titulo.pack(pady=(0, 20))

        self.campo_usuario = ctk.CTkEntry(
            self.main_frame, 
            placeholder_text="Usuário", 
            width=280,
            height=40
        )
        self.campo_usuario.pack(pady=10)

        self.campo_senha = ctk.CTkEntry(
            self.main_frame, 
            placeholder_text="Senha", 
            show="*", 
            width=280,
            height=40
        )
        self.campo_senha.pack(pady=10)

        self.botao_login = ctk.CTkButton(
            self.main_frame, 
            text="Entrar", 
            width=280,
            height=45,
            font=("Arial", 14, "bold"),
            command=self.validar_login
        )
        self.botao_login.pack(pady=25)

        self.resultado_login = ctk.CTkLabel(self.main_frame, text="", font=("Arial", 12))
        self.resultado_login.pack()

    def validar_login(self):
        usuario = self.campo_usuario.get().strip()
        senha = self.campo_senha.get().strip()
        
        if usuario == "admin" and senha == "1234":
            self.resultado_login.configure(
                text="Acesso autorizado!", 
                text_color="#2ecc71"
            )
        else:
            self.resultado_login.configure(
                text="Usuário ou senha incorretos.", 
                text_color="#e74c3c"
            )

if __name__ == "__main__":
    app = LoginApp()
    app.mainloop()