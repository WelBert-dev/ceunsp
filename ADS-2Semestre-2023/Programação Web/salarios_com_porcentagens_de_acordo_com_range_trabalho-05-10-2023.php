<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Calcular salários de acordo com range e aplicando porcentagem</title>
</head>
<body>
    <!-- 
    	REGRAS:
    	
        - Para variação entre R$ 1.500,00 e R$ 1.750,00: aplicar um aumento de 12%.
        - Para variação entre R$ 1.751,00 e R$ 2.000,00: aplicar um aumento de 10%.
        - Para mudança entre R$ 2.000,01 e R$ 3.000,00: aplicar um aumento de 7%.
        - Para acima de R$ 3.000,01: aplicar um aumento de 5%.
    -->
    
    <!-- Frontend: -->
    
    <form method="post" action="#">
        <label>Nome Funcionário:</label>
        <input type="text" name="txt_nome_funcionario" /><br/>

        <br/>
        <label>Salario Atual:</label>
        <input type="number" name="number_salario_atual" /><br/>

        <br/><br>
        <input type="submit"/>

    </form><br/>
    
    <?php
    
    # Backend: 
    
    # Nome do funcionário:
    $nome = $_POST["txt_nome_funcionario"];

    # Salário atual do funcionário:
    $salario = $_POST["number_salario_atual"];
    

    # Porcentagem de aumento de acordo com range:
    $aumento_percentagem = 0;

    if ($salario >= 1500 && $salario <= 1750) {

         # - Para variação entre R$ 1.500,00 e R$ 1.750,00: aplicar um aumento de 12%.

        $aumento_percentagem = 0.12;
    } else if ($salario >= 1751 && $salario <= 2000) {

        # - Para variação entre R$ 1.751,00 e R$ 2.000,00: aplicar um aumento de 10%.

        $aumento_percentagem = 0.10;
    } else if ($salario >= 2000.01 && $salario <= 3000) {

        # - Para mudança entre R$ 2.000,01 e R$ 3.000,00: aplicar um aumento de 7%.

        $aumento_percentagem = 0.07;
    } else if ($salario >= 3000.01) {

        # - Para acima de R$ 3.000,01: aplicar um aumento de 5%.

        $aumento_percentagem = 0.05;
    } 

    # - Validações básicas e cospe a View para o front:
    echo "<hr></hr>";
    if ($nome != "" && $salario != "" && $salario != 0) {
        echo "<p>Nome do Funcionário: ".$nome."</p>";
        echo "<p>Salário atual: R$".$salario.",00</p>";
        
        echo "<br/><p>Porcentagem contemplada: ".($aumento_percentagem * 100)."% </p>";
        echo "<p>Valor ganho para acrescentar: R$".($salario*$aumento_percentagem).",00</p>";
        echo "<p>Salário Final: R$ ".(($salario*$aumento_percentagem) + $salario).",00</p>";
    } else {
        echo "Preencha os campos, eles são OBRIGATÓRIOS para o calculo do novo salário...</p>";
    }
    
    ?>
</body>
</html>
