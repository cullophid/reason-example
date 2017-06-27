module Dom = {
  type element;
  external write : string => unit = "document.write" [@@bs.val];
  external getElementById : string => element = "document.getElementById" [@@bs.val];
  external createElement : string => element = "document.createElement" [@@bs.val];
  external appendChild : element => element => unit = "" [@@bs.send];
};



module Preact = {
  type vnode;
  external render : vnode => Dom.element => unit = "" [@@bs.send "preact"];
  external h : string => Js.t {..} => vnode = "" [@@bs.send "preact"];
};


let node name =>
    Preact.h name {"children": []};


let render vdom id => Preact.render vdom (Dom.getElementById id);


let test () => {
  let vdom  = node "h3";
  render vdom "index";
}
