
let render (state:Data.model) dispatch => {
  open Components;
  let email = state.loginForm.email;
  let password = state.loginForm.password;
  let submit event => {
    ReactEventRe.Form.preventDefault event;
    dispatch (Data.Login state.loginForm)
  };
  fullScreen [
    switch (state.user) {
      | None => empty
      | Some user => <h1> (text user.email) </h1>
    },
    row center::true middle::true fullHeight::true [
      padding [
        card [
          card_block [
            card_title "Login",
            form onSubmit::(submit) [
              formGroup [
                label "Email",
                textInput onChange::(fun v => dispatch (Data.UpdateLoginForm {...state.loginForm, email:v})) email,
              ],
              formGroup [
                label "Password",
                textInput onChange::(fun v => dispatch (Data.UpdateLoginForm {...state.loginForm, password:v})) password
              ],
              button [text "Login"]
            ]
          ]
        ]
      ]
    ]
  ]
};
