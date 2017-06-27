open Data;
let init:model = {
  loginForm: {
    email: "",
    password: ""
  },
  user: None
};

let state = ref init;

let reducer action state =>
  switch (action) {
    | UpdateLoginForm loginForm => {...state, loginForm};
    | Login loginForm => {...state, user: Some {email: loginForm.email}};

  };

let render state dispatch =>
  ReactDOMRe.renderToElementWithId (App.render state dispatch) "index";



let rec dispatch (action:Data.action) => {
  state := reducer action !state;
  render !state dispatch;
};

render !state dispatch;
