# 🚀 42 Aventuras

Todos los proyectos que he realizado durante el **Common Core de 42**, reunidos en un único repositorio. Cada carpeta conserva su propio README y su historial de commits original.

> Algunos proyectos grupales o de mayor tamaño viven en su propio repositorio y aparecen aquí como [submódulos](#-cómo-clonar-este-repositorio) (carpetas con el formato `nombre @ hash`).

---

## 📚 Índice de proyectos

| Círculo | Proyecto | Descripción | Lenguaje | Tipo |
|:-------:|----------|-------------|----------|------|
| 0 | [libft](./libft) | Mi primera librería en C: reimplementación de funciones estándar y utilidades propias | C | Individual |
| 1 | [ft_printf](./ft_printf) | Recreación de la función `printf` con argumentos variádicos | C | Individual |
| 1 | [GetNextLine](./GetNextLine) | Función que lee un archivo línea a línea desde un descriptor de fichero | C | Individual |
| 2 | [push_swap](./push_swap) | Ordenar una pila de enteros con el mínimo número de movimientos | C | Individual |
| 2 | [pipex](./pipex) | Reproducción del comportamiento de las tuberías (`pipes`) de la shell | C | Individual |
| 2 | [so_long](./so_long) | Pequeño videojuego 2D con gráficos y gestión de eventos | C (MiniLibX) | Individual |
| 3 | [philosophers](./philosophers/philo) | Problema de la cena de los filósofos: hilos, mutex y sincronización | C | Individual |
| 3 | [Minishell](https://github.com/mignavarl/La_Conchi) | Mi propia shell, con parsing, redirecciones, pipes y built-ins | C | Grupal |
| 4 | [Cub3D](https://github.com/mignavarl/mercadooma) | Motor gráfico con *raycasting* inspirado en Wolfenstein 3D | C (MiniLibX) | Grupal |
| 4 y 5 | [CPPs](./CPPs) | Módulos de C++ (00-09): clases, herencia, plantillas, STL... | C++ | Individual |
| 5 | [inception](./inception) | Infraestructura con Docker y Docker Compose (NGINX, WordPress, MariaDB) | Docker / Shell | Individual |
| 5 | [ft_irc](https://github.com/david-3lm/doscord-42_ft_irc-) | Servidor IRC propio en C++ | C++ | Grupal |
| 6 | [Transcendence_Chinchon](https://github.com/mignavarl/chinchon_transcendence) | Proyecto final del common core: aplicación web del juego del Chinchón | Web | Grupal |

---

## 🧭 Detalle por círculo

### Círculo 0

- **[libft](./libft)** — Librería propia con funciones de `libc`, manejo de memoria, cadenas y listas enlazadas. La uso como base en proyectos posteriores.

### Círculo 1

- **[ft_printf](./ft_printf)** — Implementación de `printf` con sus conversiones principales. Aprendizaje de funciones variádicas.
- **[GetNextLine](./GetNextLine)** — Lectura de líneas con gestión de buffer y *static variables*.

### Círculo 2

- **[push_swap](./push_swap)** — Algoritmo de ordenación con dos pilas y un conjunto limitado de operaciones.
- **[pipex](./pipex)** — Procesos (`fork`), tuberías (`pipe`) y ejecución de comandos (`execve`).
- **[so_long](./so_long)** — Juego 2D con MiniLibX: mapas, sprites, movimiento y validación de mapas.

### Círculo 3

- **[philosophers](./philosophers/philo)** — Hilos, mutex y prevención de *deadlocks* y *data races*.
- **[Minishell](https://github.com/mignavarl/La_Conchi)** — Intérprete de comandos con manejo de señales, variables de entorno, redirecciones, pipes y built-ins.

### Círculo 4

- **[Cub3D](https://github.com/mignavarl/mercadooma)** — *Raycasting* para renderizar un laberinto en pseudo-3D.
- **[CPPs](./CPPs)** — Primeros módulos de C++98: clases, memoria, referencias y polimorfismo básico.

### Círculo 5

- **[CPPs](./CPPs)** — Módulos restantes de C++98: excepciones, conversiones, plantillas y contenedores de la STL.
- **[inception](./inception)** — Despliegue de varios servicios con Docker Compose en una red propia.
- **[ft_irc](https://github.com/david-3lm/doscord-42_ft_irc-)** — Servidor IRC con sockets, múltiples clientes, canales y comandos.

### Círculo 6

- **[Transcendence_Chinchon](https://github.com/mignavarl/chinchon_transcendence)** — Proyecto final: aplicación web completa en equipo.

---

## 📂 Estructura del repositorio

```
42_Aventuras/
├── libft/
├── ft_printf/
├── GetNextLine/
├── push_swap/
├── pipex/
├── so_long/
├── philosophers/
├── CPPs/
├── inception/
├── Minishell/                → submódulo (La_Conchi)
├── Cub3D/                    → submódulo (mercadooma)
├── ft_irc/                   → submódulo (doscord-42_ft_irc-)
└── Transcendence_Chinchon/   → submódulo (chinchon_transcendence)
```

---

## 🔽 Cómo clonar este repositorio

Como incluye submódulos, clónalo así para descargar también su contenido:

```bash
git clone --recurse-submodules https://github.com/mignavarl/42_Aventuras.git
```

Si ya lo clonaste sin esa opción:

```bash
git submodule update --init --recursive
```

---

## ⚠️ Aviso

Estos proyectos se publican como registro de mi aprendizaje. Si estudias en 42, te animo a que los uses como referencia para entender conceptos, **no para copiarlos**: aprender de verdad pasa por escribirlos tú mismo.

---

## 👤 Autor

**mignavarl** — [GitHub](https://github.com/mignavarl)
