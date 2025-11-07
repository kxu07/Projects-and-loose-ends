setcpm(97/4)
const beat = stack(
  sound("<hh, <bd - mt bd - bd mt ->>*8").gain(0.75)
  ,note("c3 c3 ~ c3 c3 f3 g3 c4").gain(0.95)
  .sound("sawtooth").lpf(700).attack(0).decay(0.5).sustain(0).release(0)
)
const beat2 = stack(
  beat
  ,note("~ ~ ~ ~ ~ ~ c4@2").gain(1.5).sound("piano")
  .sustain(1)
  .release(1)
)
const melody = stack(
  beat
  ,note("f4@3 e4@5").gain(1.5).sound("piano")
  .sustain(1)
  .release(1)
)        
const melody2 = stack(
  beat
  ,note("f4@3 e4@2 d4 d4 d4").gain(1.5).sound("piano")
  .sustain(1)
  .release(1)
)

const melody4 = stack(
  beat
  ,note("~ d4 d4 c4@2 c4 c4 b3").gain(1.5).sound("piano").sustain(1).release(1)
)
const melody3 = stack(
  beat
  ,note("f4@2 g4 e4 d#4 e4@3").gain(1.5).sound("piano")
  .sustain(1)
  .release(1)
)
const melody5 = stack(
  beat
  ,note("~ b3 b3 a3@2 a3 a3 g3").gain(1.5).sound("piano").sustain(1).release(1)
)


cat(beat, beat2, melody, beat2, melody3, beat2, melody2, melody4, melody5)
