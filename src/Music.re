type interval =
  | Semi(int);

type note =
  | C
  | Cs
  | D
  | Ds
  | E
  | F
  | Fs
  | G
  | Gs
  | A
  | As
  | B;

let notes = [(C, 0), (Cs, 1), (D, 2), (Ds, 3), (E, 4), (F, 5), (Fs, 6), (G, 7), (Gs, 8), (A, 9), (As, 10), (B, 11)];

let note_to_string = (note) => switch note {
  | C => "C"
  | Cs => "C#"
  | D => "D"
  | Ds => "D#"
  | E => "E"
  | F => "F"
  | Fs => "F#"
  | G => "G"
  | Gs => "G#"
  | A => "A"
  | As => "A#"
  | B => "B"
}

type chord = Major(note) | Minor(note) | Seven(note);

let chord_to_string = chord => switch (chord) {
  | Major(note) => note_to_string(note)
  | Minor(note) => note_to_string(note) ++ "m"
  | Seven(note) => note_to_string(note) ++ "7"
}