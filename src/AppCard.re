module Styles = {
  open Css;

  let container =
    style([
      flex(1),
      background(white),
      borderRadius(px(16)),
      height(pct(100.)),
      maxWidth(px(800)),
      maxHeight(px(600)),
      boxShadow(~y=px(15), ~blur=px(40), rgba(0, 0, 0, 0.2)),
      padding(px(24)),
    ]);
};

[@react.component]
let make = () => {
    let (cards, nextCard) = React.useReducer((cards, _) => switch (cards) {
        | [_, ...cards] => cards
        | [] => []
    }, Repetition.make_cards());

    let chord = switch (cards) {
        | [(_, chord), ..._] => Music.chord_to_string(chord)
        | [] => "DONE"
    };

    <div className=Styles.container>
        <div>{React.string(chord)}</div>
        <button onClick={_ => nextCard()}>{React.string("Next")}</button>
    </div>;
}