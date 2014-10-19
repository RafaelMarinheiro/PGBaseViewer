# PGBaseViewer

PGBaseViewer é um código base criado para ser utilizado como fins educacionais (e.g. Projetos de PG)

PGBaseViewer deve compilar em qualquer sistema operacional. Porém, no momento, o principal suporte é dado para sistemas Unix (Linux/Mac).

## Estrutura
O código a ser modificado está na pasta ```src/PGBaseViewer```.

## Dependências

PGBaseViewer depende de:
+ CMake
    - Linux: ```$ sudo apt-get install cmake```
    - Mac: ```brew install cmake```
+ OpenGL (Normalmente já instalado no seu sistema operacional)
+ QT4
	- Linux: ```$ sudo apt-get install qt```
	- Mac: ```$ brew install qt```

## Compilando
Dentro da pasta PGBaseViewer rode:

    $ mkdir build && cd build
    $ cmake ..
    $ make

O executável deverá estar na pasta ```build/bin```
Para recompilar, basta rodar ```make``` novamente.

Qualquer dúvida, mande um e-mail para rafael@marinheiro.me.
