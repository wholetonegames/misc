for %%f in (./*.png) do (
    bin2c -o %%~nf.h %%~nf.png
)