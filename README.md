# Pipex (42) — Simulación de Pipes en C
**Utility in C to execute two commands in a pipeline, redirecting input and output through files, mimicking the shell pipe behavior.**

---

## 📌 Resumen
* **Lenguaje:** C (C99)
* **Funcionalidad:** Ejecuta dos comandos encadenados, leyendo de un archivo y escribiendo en otro.
* **Objetivo:** Aprender manejo de procesos (`fork`), redirección de entradas/salidas (`dup2`) y manejo de pipes en C.
* **Restricciones:** No se pueden usar funciones del shell directamente; todo se hace mediante **file descriptors** y **execve**.

---

## 🧠 ¿Por qué este proyecto?
Este proyecto de 42 enseña a:
* Usar **pipes** para comunicar procesos hijos.
* Redirigir entrada y salida estándar usando **`dup2`**.
* Manejar procesos con **`fork`** y esperar su finalización con **`waitpid`**.
* Trabajar con **funciones del sistema** (`open`, `execve`, `access`).
* Implementar búsqueda de comandos en el **PATH** del sistema.

👉 Este proyecto es clave para entender cómo funcionan los shells y la comunicación entre procesos en UNIX.

---

## ⚙️ Funcionamiento de Pipex

1. Abre el archivo de entrada y el archivo de salida.
2. Crea un **pipe** para comunicar dos procesos.
3. El primer hijo:
   * Redirige la entrada estándar al archivo de entrada.
   * Redirige la salida estándar al pipe.
   * Ejecuta el primer comando (`argv[2]`).
4. El segundo hijo:
   * Redirige la entrada estándar al pipe.
   * Redirige la salida estándar al archivo de salida.
   * Ejecuta el segundo comando (`argv[3]`).
5. El proceso padre:
   * Cierra ambos extremos del pipe.
   * Espera a que los hijos terminen.

---

## 🚀 Uso

### Compilación
```bash
make
```

### Ejemplo
```bash
./pipex infile "grep hello" "wc -l" outfile
```

Esto equivale a la ejecución en shell:
```bash
< infile grep hello | wc -l > outfile
```

---

## 🗂️ Estructura del proyecto
```text
pipex/
├─ pipex.c           # Lógica principal: apertura de archivos y llamada a pipex()
├─ pipex_utils.c     # Funciones auxiliares: split_cmd, get_cmd_path, exec_cmd
├─ pipex.h           # Prototipos, macros de error y cabeceras necesarias
├─ libft/            # Librería personal para utilidades (ft_split, ft_strdup, ft_putstr_fd, etc.)
├─ Makefile          # Reglas estándar (all, clean, fclean, re)
└─ README.md
```

---

## 🗂️ Explicación del código

### 📌 `pipex.c`
* **`pipex()`** → Función principal que gestiona los hijos y el pipe.
* **`dup2`** → Redirige los file descriptors a stdin/stdout.
* **`fork`** → Crea procesos hijos para ejecutar comandos.
* **`waitpid`** → Espera a que los hijos terminen antes de cerrar el programa.

📌 **Decisión clave:** Separar el flujo en dos hijos permite simular exactamente el comportamiento de un pipe en el shell.

---

### 📌 `pipex_utils.c`
* **`exec_cmd()`** → Prepara y ejecuta un comando usando `execve`. Maneja errores si el comando no existe.
* **`split_cmd()`** → Divide el comando en argumentos usando espacios.
* **`get_cmd_path()`** → Busca el ejecutable en las rutas de `PATH`.

📌 **Decisión clave:** `get_cmd_path` permite usar comandos como en un shell real, no solo rutas absolutas.

---

### 📌 `pipex.h`
* Contiene prototipos, macros de error y cabeceras necesarias (`fcntl.h`, `sys/wait.h`).
* Define mensajes de error para argumentos incorrectos, archivos no accesibles o comandos no encontrados.

---

### 📌 `Makefile`
* Reglas estándar:
  * `all`: compila el proyecto.
  * `clean`: elimina objetos `.o`.
  * `fclean`: elimina objetos y binarios.
  * `re`: recompila desde cero.

---

## 🧵 Posibles mejoras
* Manejar múltiples pipes en cadena (más de dos comandos).
* Diferenciar tipos de errores en ejecución de comandos (permiso denegado, no encontrado).
* Optimizar liberación de memoria en split y paths.

