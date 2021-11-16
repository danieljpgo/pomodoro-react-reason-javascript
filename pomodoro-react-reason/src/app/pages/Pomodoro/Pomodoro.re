type phase = 
  | Focus
  | Break;

type state = {
  seconds: int,
  ticking: bool,
  focusTime: int,
  breakTime: int,
  currentPhase: phase,
};

type action =
  | Start
  | Stop
  | Reset
  | Tick
  | TogglePhase
  | SetTimer(phase, int);

let initialState = {
  seconds: 30,
  ticking: false,
  focusTime: 25,
  breakTime: 5,
  currentPhase: Focus,
};

let reducer = (state, action) => 
  switch (action) {
    | Start => { ...state, ticking: true }
    | Stop => { ...state, ticking: false }
    | Tick => state.ticking && state.seconds > 0 
        ? { ...state, seconds: state.seconds - 1 } 
        : state
    | Reset => 
      switch (state.currentPhase) {
        | Focus => { ...state, seconds: state.focusTime * 60}
        | Break => { ...state, seconds: state.breakTime * 60}
      }
    | TogglePhase => 
      switch (state.currentPhase) {
        | Focus => { ...state, currentPhase: Break, seconds: state.breakTime * 60}
        | Break => { ...state, currentPhase: Focus, seconds: state.focusTime * 60}
      }
    | SetTimer(phase, seconds) => 
      switch (phase) {
        | Focus => { ...state, focusTime: seconds}
        | Break => { ...state, breakTime: seconds}
      }
    };


/* module resolution */
/* open File é como se fosse o import */
/* função maker é como se fosse o defaul export no reasonml */
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div>
    <PomodoroTimer seconds={state.seconds} />
    <PomodoroPanel 
      phase="Focus"
      value={state.focusTime}
      onChange={(value) => dispatch(SetTimer(Focus, value))}
    />
    <PomodoroPanel 
      phase="Break"
      value={state.breakTime}
      onChange={(value) => dispatch(SetTimer(Break, value))}
    />
    <button onClick={(_) => dispatch(TogglePhase)}>{React.string("toggle")}</button>
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