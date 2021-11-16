[@react.component]
let make = () => {
  <div>
    {React.string("test")}
    <PomodoroTimer />
    <PomodoroPanel />
  </div>
};