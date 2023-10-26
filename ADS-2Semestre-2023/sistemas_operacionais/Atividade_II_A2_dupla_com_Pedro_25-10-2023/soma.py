# Programa simples que soma dois números

# Função que soma dois números
def soma(a, b):
    return a + b

# Solicita que o usuário insira dois números
num1 = float(input("Digite o primeiro número: "))
num2 = float(input("Digite o segundo número: "))

# Calcula a soma
resultado = soma(num1, num2)

# Exibe o resultado
print("A soma de", num1, "e", num2, "é igual a", resultado)
