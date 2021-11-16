open Time;

[@react.component]
let make = (~seconds) => {
  let timer = seconds 
    |> timerFormatter 
    |> React.string; 

  <div>
    {timer}
  </div>
};