
let render (model:Data.model) dispatch => {
  switch model.user {
    | None => Login.render model dispatch
    | Some user => Home.render user
  }
};
