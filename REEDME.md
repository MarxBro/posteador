# ekeko posteador

Programita para postear usando la libreria cURL.

**Como era taaaaan facil, le agregue un ekeko geteador tambien... aunque no se bien para que.**

## Mejor explicado

Usa el metodo POST, el primer argumento es la URL y el segundo el string a postear.

Por ejemplo 'http://posteate.com' 'posteo=este+es+un+posteo+via+cuerl'.

El geteador solamente necesita una URL.

__Toda la salida va derecho a la consola, tal como viene!__

### Compilar mas o menos asi:

```bash
gcc -lcurl posteador.c -o posteador
```

