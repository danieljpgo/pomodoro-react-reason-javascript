[@react.component]
let make = (~children) => {
  <fieldset>
    <legend>{React.string("Values:")}</legend>
    {children}
  </fieldset>
};