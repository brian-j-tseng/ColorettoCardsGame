# ChameleonCards – Coloretto in C++17

Console implementation of **Coloretto**, the colour-bluffing card game.  
Draw cards into rows—or grab a row at the perfect moment—to maximise the score of **just three colours** while forcing the rest into the red!

## Components
- 76 Chameleon cards  
  - 9 × 7 colours ▸ 63  
  - 3 wild-colour Jokers  
  - 10 “+2” bonus cards  
- 5 Row cards, 5 Scoring reference cards, 1 Last-round card

*(The program builds this deck internally; no image assets required.)*

## Players

This build is **single-player only**:  
- 1 human player (you)  
- 3 computer-controlled opponents  

The A.I. follows simple heuristics (take a row when it contains ≥ 2 of its target colours, otherwise keep drawing). 

## How to Play
1. **Setup**  
   - Each player starts with 1 unique colour card (non-Joker).  
   - Shuffle deck, insert Last-round card 16 cards from bottom, deal Row cards = player count.
2. **On your turn – choose ONE action**  
   | Action | Detail |
   |--------|--------|
   | `Draw` | Flip top card, place it at the end of **any** row (max 3 cards/row). |
   | `Take` | Claim an entire row (Row card + its cards), flip that Row card face-down and sit out the rest of the round. |
3. **Round end** – when every player has taken a row, reset Row cards face-up; last taker becomes next start player.  
4. **Game end** – after the Last-round card is drawn, finish that round, then score.

### Scoring
Only your three **best** colours score positive; all others score negative.  
Wild Jokers count as any one colour. Each “+2” card adds, well, +2.  
*(The full score table is in `docs/score_table.svg` and hard-coded in `Score.cpp`.)*

> **Status: ARCHIVED / LEGACY**  
> This was a hobby project from 2018. Coding style is outdated and bugs exist.  
> Pull requests are welcome, but I keep it mainly for historical reference.


