#include <iostream>
#include <vector>
#include <string>
using namespace std;

// === Ejercicio 1: Calificaciones ===
void ejercicio1() {
    // En este caso analizo 8 notas de estudiantes para clasificarlas.
    // Me interesa saber cuántos aprobaron, reprobaron y quiénes tuvieron nota excelente.
    int aprobados = 0, excelentes = 0, reprobados = 0;
    float suma = 0;
    vector<float> notas(8); // Uso un vector para guardar las 8 notas.

    for (int i = 0; i < 8; i++) {
        // Aquí leo la nota porque después debo clasificarla.
        cout << "Ingrese nota " << i + 1 << ": ";
        cin >> notas[i];

        // Aquí comparo la nota y decido en qué grupo está.
        if (notas[i] >= 3.0 && notas[i] < 4.5) aprobados++;
        else if (notas[i] >= 4.5) excelentes++;
        else reprobados++;

        // Además voy acumulando todas las notas porque al final quiero calcular el promedio.
        suma += notas[i];
    }

    // Finalmente muestro todos los resultados de este análisis.
    cout << "\nAprobados: " << aprobados << endl;
    cout << "Excelentes: " << excelentes << endl;
    cout << "Reprobados: " << reprobados << endl;
    cout << "Promedio: " << suma / 8 << endl;
}

// === Ejercicio 2: Encuesta cine ===
void ejercicio2() {
    // En este caso recojo la edad y la calificación de los clientes del cine.
    // Con esos datos puedo medir la satisfacción y también segmentar por edades.
    int edad, calif;
    int total = 0, suma = 0, jovenes = 0, perfectos = 0;

    do {
        // Leo la edad porque si me dan 0, significa que la encuesta ya termina.
        cout << "Ingrese edad (0 para terminar): ";
        cin >> edad;
        if (edad == 0) break;

        // Leo la calificación para sumarla y analizarla después.
        cout << "Ingrese calificacion (1-10): ";
        cin >> calif;

        total++;         // Cuento la persona.
        suma += calif;   // Acumulo su calificación.

        // Aquí verifico si es joven (18 a 25) porque me interesa esa categoría.
        if (edad >= 18 && edad <= 25) jovenes++;
        // También reviso si puso nota perfecta, porque es un dato especial.
        if (calif == 10) perfectos++;
    } while (true);

    // Al final muestro todo lo que analicé.
    cout << "\nTotal encuestados: " << total << endl;
    if (total > 0) cout << "Promedio calificacion: " << (float)suma / total << endl;
    cout << "Jovenes (18-25): " << jovenes << endl;
    cout << "Con calificacion perfecta: " << perfectos << endl;
}

// === Ejercicio 3: Orden ascendente ===
void ejercicio3() {
    // Aquí quiero analizar si los números ingresados se encuentran en orden ascendente.
    int n;
    cout << "Cuantos numeros desea ingresar? ";
    cin >> n;

    if (n <= 0) {
        cout << "Debe ingresar al menos un numero.\n";
        return;
    }

    int num, anterior;
    bool asc = true;

    // Leo el primer número para tener una base de comparación.
    cout << "Ingrese el primer numero: ";
    cin >> anterior;

    for (int i = 2; i <= n; i++) {
        // Leo cada nuevo número para compararlo con el anterior.
        cout << "Ingrese el numero " << i << ": ";
        cin >> num;

        // Si el número actual no es mayor que el anterior, entonces ya no es ascendente.
        if (num <= anterior) asc = false;

        // Muestro la diferencia porque me ayuda a verificar la relación entre ellos.
        cout << "Diferencia con anterior: " << num - anterior << endl;

        anterior = num; // Actualizo el valor de referencia.
    }

    // Doy la conclusión de mi análisis.
    cout << (asc ? "Los numeros SI estan en orden ascendente.\n"
                 : "Los numeros NO estan en orden ascendente.\n");
}

// === Ejercicio 4: Descuentos ===
void ejercicio4() {
    // Aquí analizo el precio final de una compra aplicando descuentos según la cantidad.
    int cantidad;
    float precio, desc = 0, subtotal, total;

    // Primero leo la cantidad y el precio unitario porque son la base del cálculo.
    cout << "Ingrese cantidad: ";
    cin >> cantidad;
    cout << "Ingrese precio unitario: ";
    cin >> precio;

    subtotal = cantidad * precio; // Calculo el subtotal antes de descuento.

    // Ahora me pregunto: ¿qué descuento corresponde según la tabla?
    if (cantidad > 10 && cantidad <= 20) desc = 0.05;
    else if (cantidad > 20 && cantidad <= 50) desc = 0.10;
    else if (cantidad > 50) desc = 0.15;

    total = subtotal - (subtotal * desc); // Aplico el descuento.

    // Muestro todo el detalle para entender el proceso.
    cout << "\nSubtotal: " << subtotal << endl;
    cout << "Descuento aplicado: " << desc * 100 << "%" << endl;
    cout << "Total a pagar: " << total << endl;
}

// === Ejercicio 5: Primer caracter no repetido ===
void ejercicio5() {
    // Aquí leo una palabra y quiero saber: ¿cuál es la primera letra que no se repite?
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    bool encontrado = false;

    for (int i = 0; i < palabra.length(); i++) {
        char actual = palabra[i];
        int contador = 0;

        // Recorro toda la palabra para contar cuántas veces aparece este carácter.
        for (int j = 0; j < palabra.length(); j++) {
            if (palabra[j] == actual) contador++;
        }

        // Si aparece solo una vez, ya encontré mi respuesta.
        if (contador == 1) {
            cout << "El primer caracter no repetido es: " << actual << endl;
            encontrado = true;
            break;
        }
    }

    // Si no encontré ninguno, informo que todos se repiten.
    if (!encontrado) cout << "Todos los caracteres se repiten.\n";
}

// === Ejercicio 6: Fibonacci ===
void ejercicio6() {
    // Aquí leo un número n y genero la secuencia de Fibonacci hasta ese término.
    int n;
    cout << "Ingrese cantidad de terminos: ";
    cin >> n;

    int a = 0, b = 1, c;

    cout << "Serie Fibonacci: ";
    for (int i = 0; i < n; i++) {
        // Muestro el valor actual.
        cout << a << " ";
        // Actualizo los valores sumando los dos anteriores.
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// === Menu principal ===
int main() {
    int opcion;
    do {
        // Este menú me sirve para organizar todos los programas en un solo archivo.
        cout << "\n===== MENU =====\n";
        cout << "1. Calificaciones (8 estudiantes)\n";
        cout << "2. Encuesta cine\n";
        cout << "3. Orden ascendente\n";
        cout << "4. Descuentos\n";
        cout << "5. Primer caracter no repetido\n";
        cout << "6. Serie Fibonacci\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        // Según lo que elija, llamo al ejercicio correspondiente.
        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0); // Repito el menú hasta que el usuario quiera salir.

    return 0;
}
