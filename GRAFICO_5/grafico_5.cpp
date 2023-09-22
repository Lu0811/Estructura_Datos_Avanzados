#include <iostream>
#include <fstream>
#include <random>

int main()
{
    const int num_points = 50;  // Número de puntos aleatorios a generar
    const int dimension = 1000; // Número de dimensiones de cada punto (cambia según sea necesario)

    // Configurar el generador de números aleatorios con una semilla específica (por ejemplo, 42)
    std::mt19937 gen(42);                                 // Generador Mersenne Twister con semilla 42
    std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribución uniforme en el rango [0.0, 1.0]

    // Abrir un archivo para guardar los puntos aleatorios en formato CSV
    std::ofstream outfile("random_points.csv");

    // Generar 'num_points' puntos aleatorios
    for (int i = 0; i < num_points; ++i)
    {
        // Generar 'dimension' valores para cada punto
        for (int j = 0; j < dimension; ++j)
        {
            if (j > 0)
                outfile << ",";  // Separar los valores con comas, excepto el primero
            outfile << dis(gen); // Escribir un valor aleatorio en el archivo
        }
        outfile << "\n"; // Cambiar de línea para el siguiente punto
    }

    // Cerrar el archivo después de escribir todos los puntos
    outfile.close();

    return 0; // Terminar el programa con éxito
}
