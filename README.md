# Serial Debugger

## Checando comunicação

Para checar se a Nucleo está enviando os dados pela serial corretamente, pode-se abrir um terminal serial usando o [miniterm](https://pythonhosted.org/pyserial/tools.html#miniterm) do [pyserial](https://pythonhosted.org/pyserial/index.html).

```bash
python3 -m serial.tools.miniterm /dev/ttyACM0 115200
```

A seguinte saída deve aparecer

```bash
--- Miniterm on /dev/ttyACM0  115200,8,N,1 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
Msg: 0000
Msg: 0001
Msg: 0002
...
```
