<CsoundSynthesizer>
<CsOptions>
-+rtaudio=jack -odac --opcode-lib=../build/libtriglinseg.so
</CsOptions>
<CsInstruments>
0dbfs = 1
nchnls = 2
ksmps = 32

instr 1
kTrig metro .25
kEnv triglinseg kTrig, 0, 1, 500, .1, 0, .25, 100, .25, 0
a1 oscili 1, kEnv
outs a1, a1
endin

instr 2
kTrig metro .25
aEnv triglinseg kTrig, 0, 1, 500, .1, 0, .25, 100, .25, 0
a1 oscili 1, aEnv
outs a1, a1
endin

</CsInstruments>
<CsScore>
i1 0 10
i2 10 10
</CsScore>
</CsoundSynthesizer>