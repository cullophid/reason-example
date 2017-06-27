let text value => ReactRe.stringToElement value;

let empty = ReactRe.nullElement;

let padding children => {
  <div style=(ReactDOMRe.Style.make paddingTop:: "15px" paddingBottom::"15px" ())> (ReactRe.listToElement children) </div>
};

let container children => {
  <div className="container-fluid"> (ReactRe.listToElement children) </div>
};

let style = ReactDOMRe.Style.make;

let row
  ::center=false
  ::middle=false
  ::fullHeight=false
  children => {
    let className = "row"
      ^ (if center " align-items-center" else "")
      ^ (if middle " justify-content-center" else "");

    let _style = fullHeight ? style height:: "100%" () : style ();
    <div className=(className) style=(_style)> (ReactRe.listToElement children) </div>
};

let col children => {
  <div className="col"> (ReactRe.listToElement children) </div>
};

let fullScreen children => {
  <div style=(style width:: "100vw" height::"100vh" ())> (ReactRe.listToElement children) </div>
};


let card children => {
  <div className="card"> (ReactRe.listToElement children) </div>
};

let card_block children => {
  <div className="card-block"> (ReactRe.listToElement children) </div>
};

let card_title title => {
  <h4 className="card-title"> (text title) </h4>
};



let form ::onSubmit children => {
  <form onSubmit=(onSubmit)> (ReactRe.listToElement children) </form>
};

let formGroup children => {
  <div className="form-group"> (ReactRe.listToElement children) </div>
};

let label value => {
  <label> (text value) </label>
};

let textInput ::_type="text" ::onChange value => {
  let targetValue event => (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
  <input
    className="form-control"
    _type=(_type)
    onChange=(fun e => onChange (targetValue e))
    value=(value)
    />
};

let button ::onClick=? children => {
  let clickHandler = switch onClick {
    | None => fun _ => ()
    | Some f => f
  };
  <button className="btn btn-default btn-block" onClick=(clickHandler)> (ReactRe.listToElement children) </button>
};
