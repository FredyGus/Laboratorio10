# 🧪 Laboratorio: Gestión de Miembros de un Club en C++

## 🎯 Objetivo

El objetivo de este laboratorio es que los estudiantes practiquen **la manipulación de archivos en C++** utilizando la librería `<fstream>`.  
Se implementa un programa para **gestionar un club de manera sencilla**, permitiendo:

✅ Almacenar  
✅ Actualizar  
✅ Eliminar  
✅ Recuperar datos de miembros desde un archivo llamado `club.txt`.

---

## 💡 Requisitos Previos

- Conocimientos básicos de clases en C++
- Uso de ciclos y condicionales
- Manejo de la librería `<fstream>`
- Uso del entorno de desarrollo **Visual Studio Community**

---

## ⚙️ Funcionalidad del Programa

El programa permite administrar una lista de miembros mediante un **menú interactivo**.  
Se utiliza un archivo plano (`club.txt`) como base de datos para almacenar los datos de los miembros del club.

### 📂 Archivo utilizado
- **`club.txt`**: Guarda los datos en el formato:  
  `nombre,edad,correo`

---

## 🏗️ Estructura del Código

### 🔧 Clase `MiembroClub`

Contiene los siguientes atributos:

- `nombre` (string)  
- `edad` (int)  
- `correo` (string)

### 🛠️ Métodos

| Método | Descripción |
|--------|-------------|
| `guardarEnArchivo()` | Guarda un nuevo miembro en el archivo |
| `leerDesdeArchivo()` | Muestra todos los miembros guardados |
| `actualizarMiembro(nombre, nuevoCorreo)` | Modifica el correo de un miembro específico |
| `eliminarMiembro(nombre)` | Elimina un miembro por su nombre |

---

## 🖥️ Menú del Programa

```bash
---- Menú del Club ----
1. Agregar miembro
2. Mostrar miembros
3. Actualizar miembro
4. Eliminar miembro
5. Salir
