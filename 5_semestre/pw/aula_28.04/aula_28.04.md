# Aula 28.04 - Setup MVC com JSF
Nessa aula, vamos configurar alguns Setups para o CRUD que iremos criar na matéria.  
O código completo da aula está disponível no arquivo [OlaJSF.zip](./OlaJSF.zip)

## Ferramentas Utilizadas
Vamos utilizar algumas ferramentas para tornar esse CRUD possível, como o Payara Server e o JSF.
### Payara Server
**Configuração**  
Para configurar o Payara Server, basta acessar a aba ``Services > Botão Direito em Server > Add Server > Payara Server``
### JavaServer Faces - JSF
**O que é**  
É um framework de interface de usuário (UI) para Java Web, implementado para facilitar o trabalho de escrita
de um HTML do zero.  
**Arquitetura**  
A arquitetura utilizada é a MVC (Model, View e Controller).
* Model: Comunicação com o Banco;
* View: Interface;
* Controller: Controladores entre Interface e Comunicação com o Banco.

## Controller
Por padrão, os Controllers que serão usados por facelets devem receber um nome. Esse nome se dá pelo Decorator **@Named**, sendo usado como ``@Named(value="controleIndex")``, nome que será identificado pela Facelet.
### Escopo da classe
Os métodos disponíveis através de Getter e Setter podem ser usado nas Facelets para exibir os dados armazenados na classe do Controller.
* **@RequestScoped**: Ciclo de vida mais curto (dura a cada atualização da página);
* **@SessionScoped**: Ciclo de vida de sessão de usuário (configurada de forma padrão para 30 minutos);
* **@ApplicationScoped**: Ciclo de vida mais longo (uma aplicação singleton, onde todos os usuários acessam a mesma coisa).

### Roteamento (Navegação entre páginas)
O retorno de Strings permite a navegação entre páginas:
```java
public String sobre() {
    return "sobre";
}

public String index() {
    return "index"; 
}
```
Entretanto, a navegação pode ser problemática por conta do handshake do JSF, que de forma alternativa, podemos corrigir o redirecionamento.
```java
public String sobre() {
    return "sobre?faces-redirect=true";
}

public String index() {
    return "index?faces-redirect=true"; 
}
```

## View
Para as views, serão utilizadas Facelets (xhtml). Exemplo de View:
```xml
<html xmlns="http://www.w3.org/1999/xhtml"
      xmlns:h="http://xmlns.jcp.org/jsf/html"
      xmlns:f="http://xmlns.jcp.org/jsf/core">
    <h:head>
        <title>Facelet Title</title>
    </h:head>
    <h:body>
        <h1>Hello World</h1>
    </h:body>
</html>
```

### Consumo de um Getter da Classe
É possível obter dados disponíveis na classe através do método Getter de uma variável, da seguinte forma:
```xml
<h:outputText value="#{controleIndex.ola}" />
```
O **h:outputText** faz parte da namespace do jsf/html. Dessa forma, é possível acessar os atributos de uma classe para exibição.  
Como outro exemplo, temos uma data e sua formatação pra exibição:
```xml
<h:outputText value="#{controleIndex.dataSO.time}">
    <f:convertDateTime pattern="dd/MM/yyyy HH:mm:ss:SSS" timeZone="America/Sao_Paulo" />
</h:outputText>
```
O **f:convertDateTime** é um utilitário da namespace do jsf/core.