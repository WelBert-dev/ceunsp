Para incluir a biblioteca ArduinoUnit segue os passos abaixo:

1. **Baixe a Biblioteca ArduinoUnit:**
   - Visite a página da biblioteca ArduinoUnit no GitHub: [ArduinoUnit](https://github.com/mmurdoch/arduinounit)
   - Clique no botão verde "Code" e selecione "Download ZIP" para baixar o arquivo ZIP da biblioteca.

2. **Instale a Biblioteca no Arduino IDE:**
   - Abra o Arduino IDE.
   - Vá para "Sketch" > "Include Library" > "Add .ZIP Library...".
   - Selecione o arquivo ZIP que você baixou.

3. **Verifique a Instalação:**
   - No Arduino IDE, vá para "File" > "Examples" > "ArduinoUnit" e escolha um dos exemplos para verificar se a biblioteca foi instalada corretamente.
   - O exemplo "exampleAssert" é um bom ponto de partida.

4. **Crie seu Projeto com ArduinoUnit:**
   - Agora você pode criar seu próprio código usando a biblioteca ArduinoUnit. Comece incluindo a biblioteca no início do seu arquivo de código:
     ```cpp
     #include <ArduinoUnit.h>
     ```

   - Em seguida, você pode começar a escrever seus testes usando as macros e funções fornecidas pela ArduinoUnit.

5. **Carregue e Execute no Arduino:**
   - Carregue o código no seu Arduino e abra a janela Serial para visualizar os resultados dos testes.


### Obs: Os testes unitários devem ser realizados com o Arduíno conectado no computador?

- A biblioteca ArduinoUnit permite que você execute testes unitários diretamente no Arduino sem a necessidade de estar conectado ao PC. Uma vez que você tenha carregado o código de teste no Arduino, ele executará os testes e exibirá os resultados na PORTA SERIAL.

- Portanto, a execução dos testes pode ser monitorada através da JANELA SERIAL DO ARDUINO IDE. 