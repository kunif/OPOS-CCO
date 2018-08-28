if .%1==. goto :end
if not exist z%1\* goto :end
cd z%1
del %1.h
del %1_i.c
del %1_p.c
del %1.tlb
del %1.*.user
del %1.*.vspscc
del dlldata.c
rd /s /q Release
rd /s /q Debug
cd ..
:end
