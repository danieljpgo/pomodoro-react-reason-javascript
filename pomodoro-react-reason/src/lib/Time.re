open Number;

let timerFormatter = (timeInSeconds) => {
  let minutes = timeInSeconds / 60;
  let seconds = timeInSeconds mod 60;
  let minutesStr = minutes 
    |> string_of_int 
    |> padDecimalNumber;
  
  let secondsStr = seconds 
    |> string_of_int 
    |> padDecimalNumber;
  
  minutesStr ++ ":" ++ secondsStr;
};