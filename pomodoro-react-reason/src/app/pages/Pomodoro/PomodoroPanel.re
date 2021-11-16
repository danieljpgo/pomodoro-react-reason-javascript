/* 
 * ReactEvent.Form.target##value
 * Sintaxe responsavel por interoperar Reason com JavaScript
 **/

[@react.component]
let make = (~phase, ~value, ~onChange) => {
  <div>
    <div>{React.string(phase)}</div>
    <input 
      type_="number"
      value={string_of_int(value)}
      onChange={(e) => e -> ReactEvent.Form.target##value |> onChange}
    />
  </div>
};