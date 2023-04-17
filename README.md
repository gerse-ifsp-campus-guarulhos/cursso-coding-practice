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
