type state = {
  seconds: int,
  ticking: bool,
};

type action =
  | Start
  | Stop
  | Reset
  | Tick;

let initialState = {
  seconds: 30,
  ticking: false,
};

let reducer = (state, action) =>
  switch (action) {
    | Start => { ...state, ticking: true }
    | Stop => { ...state, ticking: false }
    | Reset => { ...state, seconds: 30 }
    | Tick => state.ticking && state.seconds > 0 
        ? { ...state, seconds: state.seconds - 1 } 
        : state
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div>
    {React.string(string_of_int(state.seconds))}
    <button onClick={(_) => dispatch(Start)}>{React.string("start")}</button>
    <button onClick={(_) => dispatch(Stop)}>{React.string("stop")}</button>
    <button onClick={(_) => dispatch(Reset)}>{React.string("reset")}</button>
  </div>
};















  /* React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  }); */


  /* <PomodoroTimer />
  <PomodoroPanel /> */