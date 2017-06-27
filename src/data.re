type loginForm = {
  email: string,
  password: string
};

type user = {
  email: string
};

type model = {
  loginForm: loginForm,
  user: option user,
};

type action =
  UpdateLoginForm loginForm
  | Login loginForm;
