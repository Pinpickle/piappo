module Styles = {
  open Css;

  global(
    "body",
    [
      fontFamily(
        "-apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Helvetica, Arial, sans-serif, \"Apple Color Emoji\", \"Segoe UI Emoji\", \"Segoe UI Symbol\"",
      ),
    ],
  );

  global("*,::before,::after", [boxSizing(borderBox)]);

  let container =
    style([
      position(absolute),
      width(pct(100.)),
      height(pct(100.)),
      left(px(0)),
      top(px(0)),
      background(
        linearGradient(
          deg(180),
          [(0, hex("EDF1F3")), (100, hex("DEE8ED"))],
        ),
      ),
      padding(px(32)),
      display(flexBox),
      justifyContent(center),
      alignItems(center),
    ]);
};

[@react.component]
let make = () => <div className=Styles.container> <AppCard /> </div>;