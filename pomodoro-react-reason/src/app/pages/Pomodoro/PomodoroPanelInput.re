/* 
 * ReactEvent.Form.target##value
 * Sintaxe responsavel por interoperar Reason com JavaScript
 **/

[@react.component]
let make = (~label, ~value, ~onChange) => {
  <div>
    <label htmlFor={label}>{React.string(label)}</label>
    <input 
      type_="number"
      id={label}
      value={string_of_int(value)}
      onChange={(e) => e -> ReactEvent.Form.target##value |> onChange}
    />
  </div>
};