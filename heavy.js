setcpm(97/4)
const drumbeat = sound("<hh, <bd - lt bd - bd lt ->>*8").gain(0.5)

const beat = stack(
  drumbeat
  ,note("c2 c2 ~ c2 c2 f2 g2 c3").gain(1)
  .sound("gm_acoustic_bass").lpf(500).attack(0).decay(0.5).sustain(0).release(0)
)
const beat2 = stack(
  beat
  ,note("~ ~ ~ ~ ~ ~ c4@2").gain(1.2).sound("piano")
  .attack(.01)
  .sustain(1)
  .release(1)
)
const melody = stack(
  beat
  ,note("f4@3 e4@5").gain(1.2).sound("piano")
  .attack(.01)
  .sustain(1)
  .release(1)
)   

const guitarbeat = 
  note("g2 g2 ~ g2 g2 ~ a3 g3 ").s("sawtooth").lpf(700).gain(0.5)

const melody2 = stack(
  beat
  ,note("f4@3 e4@2 d4 d4 d4").gain(1.2).sound("piano")
  .attack(.01)
  .sustain(1)
  .release(1)
  ,note("~ ~ ~ ~ ~ ~ g3 g2").s("sawtooth").lpf(700).gain(0.5)
)

const melody4 = stack(
  beat
  ,guitarbeat
  ,note("~ d4 d4 c4@2 c4 c4 b3").gain(1.2).sound("piano").sustain(1).release(1)
  .attack(.01)
)
const melody3 = stack(
  beat
  ,note("f4@2 g4 e4 d#4 e4@3").gain(1.2).sound("piano")
  .sustain(1)
  .release(1)
  .attack(.01)
)
const melody5 = stack(
  beat
  ,guitarbeat
  ,note("~ b3 b3 a3@2 a3 a3 g3").gain(1.2).sound("piano").sustain(1).release(1)
  .attack(.01)
)

const melody6 = stack(
  beat
  ,guitarbeat
  ,note("~ ~ ~ ~ ~ ~ a3 g3").gain(1.2).sound("piano").sustain(1).release(1)
  .attack(.01)
)

cat(drumbeat, drumbeat, beat, beat2, melody, beat2, melody3, beat2, melody2, melody4, melody5)
