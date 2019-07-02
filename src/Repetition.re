open Music;

let uniq_cons = (x, xs) =>
  if (List.mem(x, xs)) {
    xs;
  } else {
    [x, ...xs];
  };

let remove_from_right = List.fold_right(uniq_cons, _, []);

let cards =
  [
    Major(C),
    Minor(D),
    Major(E),
    Major(F),
    Major(G),
    Minor(A),
    // F
    Major(F),
    Minor(G),
    Major(A),
    Major(As),
    Major(B),
    Minor(C),
    // D
    Major(D),
    Minor(E),
    Major(Fs),
    Major(G),
    Major(A),
    Minor(B),
    // A
    Major(A),
    Minor(B),
    Major(Cs),
    Major(D),
    Major(E),
    Minor(Fs),
  ]
  ->remove_from_right
  ->List.map(chord => (chord_to_string(chord), chord), _);

let rec shuffle = list =>
  switch (list) {
  | [] => []
  | [single] => [single]
  | list =>
    let (before, after) = List.partition(_ => Random.bool(), list);
    List.rev_append(shuffle(before), shuffle(after));
  };

let make_cards = () => shuffle(cards)
