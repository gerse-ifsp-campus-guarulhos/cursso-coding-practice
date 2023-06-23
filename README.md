# **curso-coding-practice**




Nesse curso / guia de codificação será apresentado métodos práticos, passos e técnicas de codificação que englobam boas práticas e organização dos códigos, visando facilitar o mantenimento, desenvolvimento e trabalho de equipe em projetos de software. Como técnica será utilizado máquina de estados para modelar o processo e traduzi-lo para código, assim tendo um processo de desenvolvimento mais sistemático e compreensível. Também é importante pontuar  que esse curso / guia é focado predominantemente na prática e não na teoria, contudo caso queira se aprofundar em alguns conceitos que serão apresentados aqui sinta-se livre para estudá-los mais a fundo.

<br>
<br>
<br>

## **Materiais e recursos**

 Será utilizado o kit educacional [Shield Edu IFSP](https://github.com/gerse-ifsp-campus-guarulhos/ShieldEdu-IFSP) e um Arduino uno, que integrará o ambiente de estudo junto do editor de texto e compilador. É aconselhável utilizar o `vscode`  embora o conteúdo mostrado aqui não dependa do ambiente de desenvolvimento, dessa forma é plenamente possível utilizar outros ambientes.

<br>

## **Conteúdo programático**
 * Preparando o ambiente;
 * Boas práticas;
 * Passos iniciais no projeto;
 * Funções;
 * Bibliotecas;
 * Máquina de estados finitos;
 * Exercício.

<hr><br><br>


### **Preparando o ambiente**

Será utilizado o [Visual Studio Code](https://code.visualstudio.com/) junto da extensão [platformio](https://platformio.org/platformio-ide), o Vscode é multiplataforma portanto não há restrições quanto ao sistema operacional.

<br>

**Extensão obrigatórias:**
 * [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

<br>

**Extensão opcionais:**
 * [Template Generator](https://platformio.org/platformio-ide)
 * [TODO Highlight](https://marketplace.visualstudio.com/items?itemName=wayou.vscode-todo-highlight)
 * [Better Comments](https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments)
 * [Better C++ Syntax](https://marketplace.visualstudio.com/items?itemName=jeff-hykin.better-cpp-syntax)

<br>

Após instalar o `vscode` vá no canto inferior esquerdo em `settings / extensions`, pesquise e instale as extensões listadas acima. Esse processo de instalação também é possível de ser feita pelo terminal, nesse caso os procedimento de instalação estarão descritos na documentação de cada extensão.

<br>

A pós terminar reinicie o `vscode`, e então clique no ícone (de alienígena) do `platformio` que se encontra painel lateral esquerdo, clique em "Create new project" e na página inicial em "New Project". Então crie um projeto com as seguintes especificações:

<br>

 * **Name**: aula-maquina-de-estados
 * **Board**: Arduino Uno
 * **Framework**: Arduino
 * **Location**: ..../workspace/GERSE/

<br>

Fique atento no local onde o projeto será salvo, de preferencia adote uma pasta reservada para eles, isso irá ajudará na organização. Por esse motivo a indicação do local é `workspace/GERSE/`, onde a lógica seria que em `workspace` é dedicada a manter projeto em geral e a pasta `GERSE` os projetos do grupo de robótica. Assim a organização será semelhante a esta:


```
 |
 |-- workspace
 |     |-- GERSE
 |     |    |--aula-maquina-de-estados
 |     |    |    |-arquivos do projeto
 |     |

```

<br>

### **Boas práticas**


Há uma série de passos e métodos que vão pautar a forma como o código deve ser construído, seja um padrão local como adotado no grupo de robótica ou global, como a convenção de nomenclatura de variáveis, métodos e objetos  no Java e outras linguagens orientadas a objetos. Isso é algo amplamente discutido sobretudo na engenharia de software, mas que no fim acaba melhorando a qualidade do código e consequentemente seu entendimento, desenvolvimento e mantenimento (manutenção).

<br>

Primeiro de tudo é como deve-se pensar para codificar alguma coisa ou processo, arriscando dizer que essa é uma das etapas mais significativas para o desenvolvimento de qualquer coisa, assim como códigos, mecanismos, teses, textos, ideias, entre outros. Junto a isso um método e ou modelos sistemáticos permitem que algo abstrato ou “complexo” possa ser traduzido para para uma linguagem matemática, permitindo análises mais profundas e construções de detecção de  padrões. Bons exemplos disso são as redes de petri e máquina de estados  finitos, assuntos que serão discutidos ao decorrer deste guia e em outros cursos.

<br>

Então apresento o pensamento cartesiano, criado pelo filósofo René Descarte, mostrado em sua obra “O Discurso do Método".  Que de forma resumida busca um método de como alcançar o conhecimento racional, desmembrando-o em pedaços simples e de fácil entendimento. Trazendo isso para o nosso contexto iremos pegar ideias grandes, detalhadas e complexas e “quebrá las” em pequenas parcelas, sedo elas menores possíveis. Isso será posto em prática a seguir nos tópicos de funções, bibliotecas e máquinas de estados.

<br>

Além da forma de construir e dividir o código, nomear coisas e padrões devem ser adotados e seguidos. Por exemplo imagine operação matemática, no caso de divisão:

<br>

```
float fNumerador		= 10;
float fDenominador		= 10;

float fResposta 		= fNumerador / fDenominador;

```

<br>

Os nome são dados para identificar o que cada variável armazena ou representa, o mesmo deve ser seguido para funções que deve ser nomeadas pela a ação faz:

<br>

```
static float math_sfDividir( float fNumerador,  float fDenominador) {
	return fNumerador / fDenominador;
}
```

Claro que outras há questões que relacionado a funções quando falamos de boas praticas e códigos limpos, mas nesse momento nosso foco está nos nomes, convenções e padrões. Agora tente identificar o que a próxima função faz em detrimento de seu nome e das variáveis e parâmetros  que ela contém :

<br>

```
int func(int a, float b, char* string) {

	int k = 0;

	[ ... ]

	return k;
}
```

<br>


Obviamente é simplesmente impossível saber o que essa função faz sem que tenhamos que analisar o código interno e **tentar** entendê-lo, e nesse caso corrigir um problema ou alterar e adicionar uma nova etapa, torna-se uma tarefa mais complexa e com mais provabilidade a falhar. Se tivessem adotado nomes melhores isso seria mais simples de entender, e consequentemente realizar outras atividades em cima dessa função seria uma atividade mais amigável. Imagine o exemplo da divisão com o numerador e denominador com a ordem trocada, seria mais intuitivo identificar o que foi feito errado.

<br>

Devem ter percebido alguns detalhes nos nomes adotados além do que a função fáz ou do que a variável armazena, no caso **f**Denominador e **math_sf**Dividir. Isso é o que chamamos de convenção que são geralmente adotado por times, empresas,  e outros coletivos. No caso dos exemplos a convenção é:

<br>

 1. As funções e variável deve ter seus tipos identificados usando a primeira letra do tipo declarado e o Nome da entidade deve começar com letra maiúscula:

<br>

 ```
char cLetra = 'a';

float fOffset = 42,4242;

static unsigned long int suliTime = 953221475;
 ```

<br>  

 2. Antes dos nomes e tipos de uma função deve ser identificado a biblioteca de origem sempre sento separados por underline `_`, o exemplo a seguir mostra os protótipos de funções que pertence a biblioteca `matematica.h` identificada como `math` :

 <br>

```
float math_fDividir( ... );

float math_fSomar( ... );

long doble math_ldFatorial( ... );
```

<br>

 3. Contantes e macros devem ser escritas todas em caixa alta e identificadas de forma semelhante a funções, veja o exemplo de *defines* do arquivo `config.h`:

<br>

 ```
#define configTIME_OVERFLOW_MS	( 5000 )

#define configQUEUE_SIZE ( 5 )

#define configOFFSET ( 42 )

#define configSAMPLES( PERIOD ) ( PERIOD * configTIME_OVERFLOW_MS )
```

<br>

Quanto a comentários estes devem ser evitados, apesar de contra intuitivo eles podem poluir o código e serão mais coisas para manter, dado que se alterado algo os comentários devem ser atualizados para evitar a disparidade de informações. Se a nomenclatura e as funções forem construídas de maneira adequada, o código **será e deve ser auto explicativo**, assim não tendo a necessidade de muitos comentários.

<br>

Em outro contexto, como linguagem orientada a objetos, muitos comentários podem indicar que seu código contém algum problema conceitual, ou até só uma adoção de nomes ruins.  Mas é possível que haja um contexto que será necessário ter comentários, por exemplo em muitos programas embarcados em microcontrolador há uma concorrência por um recurso  como um temporizador usado para criar um sinal PWM (modulação de pulso por largura), então ao criar uma biblioteca ou funções que abstrai as operações dedicadas manipular os registradores do periférico é importante destacar o uso do recurso, a fim de evitar problema futuros.

<br>

Apesar disso comentários são bem vindo para documentar o **processo**, e também quando o código se trata de uma SDK (kit de desenvolvimento de código) que necessitam de muito mais detalhamento do seu funcionamento.


<br>

Seguindo essas etapas podemos chegar em códigos mais limpos e entendíveis, mesmo que o leitor não tenha muito conhecimento sobre o assunto, além de facilitar o trabalho em equipe e permitir outras vantagem já citados anteriormente.

<br>

**Indicação de leitura e pesquisa:**


 - (livro) Orientação a Objetos e Solid para Ninjas, Projetando classes flexíveis, de Maurício Aniche 
 - (livro) Código Limpo, Habilidade Praticas do Agile Software, de Robert C. Martin
 - (pesquisa) Pensamento cartesiano, René Descartes
