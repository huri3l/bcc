# Aula 05.05 - Ajax, JSF e Prime Faces
Nessa aula, vamos criar um projeto do zero e fazer sua configuração para comunicar a interface JSF com o controle do projeto.

## Criação do Projeto
Para criar o projeto (usando NetBeans), basta ir em ``New Project > Java With Maven > Web Application``.

## Comunicação entre a Interface com o Controle
O exemplo que vamos usar para a comunicação será a de Entrada e Saída, onde iremos processar a entrada de um Input e atualizar o valor de outro mediante a entrada enviada, usando o Ajax para fazer a se comunicar.  
Além disso, precisamos de um Controle e de uma Interface para se comunicarem. 
### Controle
Para criar o controle, vamos fazer um Package ``br.edu.ifsul.controle``, e criar a classe ``ControleAjax``.
Dentro do controle, vamos criar o seguinte código:  
**ControleAjax.java**
```java
package br.edu.ifsul.controle;

import java.io.Serializable;
import javax.faces.view.ViewScoped;
import javax.inject.Named;

@Named(value = "controleAjax")
@ViewScoped
public class ControleAjax implements Serializable {
    private String entrada;
    private String saida;
    
    public ControleAjax() {
        
    }
    
    public void processar() {
        this.saida = "Você digitou com Ajax: " + entrada;
    }

    public String getEntrada() {
        return entrada;
    }

    public void setEntrada(String entrada) {
        this.entrada = entrada;
    }

    public String getSaida() {
        return saida;
    }

    public void setSaida(String saída) {
        this.saida = saída;
    }
}
```

### Interface
Para a intrface, vamos criar um arquivo index.xhtml na pasta Web Pages. Esse será o arquivo principal da interface do projeto e o qual nós iremos testar.  
**index.xhtml**
```html
<?xml version='1.0' encoding='UTF-8' ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
      xmlns:h="http://xmlns.jcp.org/jsf/html"
      xmlns:f="http://xmlns.jcp.org/jsf/core"
          
      xmlns:p="http://primefaces.org/ui">
    <h:head>
        <title>Usando Ajax com JSF</title>
    </h:head>
    <h:body>
        <h:form>
            <h:panelGrid columns="2">
                <h:outputLabel value="Entrada" for="txtEntrada" />
                <h:inputText value="#{controleAjax.entrada}" id="txtEntrada" />
                <h:outputLabel value="Saída" for="txtSaida" />
                <h:inputText value="#{controleAjax.saida}" id="txtSaida" />
                <h:commandButton value="Processar" actionListener="#{controleAjax.processar()}">
                    <f:ajax render="txtSaida" execute="txtEntrada" />
                </h:commandButton>
            </h:panelGrid>
        </h:form>
    </h:body>
</html>
```

### Configuração web.xml
É necessário atualizar o web.xml, arquivo responsável pela organização dos arquivos e páginas do Frontend.
```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app version="4.0" xmlns="http://xmlns.jcp.org/xml/ns/javaee" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd">
    <context-param>
        <param-name>javax.faces.PROJECT_STAGE</param-name>
        <param-value>Development</param-value>
    </context-param>
    <servlet>
        <servlet-name>Faces Servlet</servlet-name>
        <servlet-class>javax.faces.webapp.FacesServlet</servlet-class>
        <load-on-startup>1</load-on-startup>
    </servlet>
    <servlet-mapping>
        <servlet-name>Faces Servlet</servlet-name>
        <url-pattern>*.xhtml</url-pattern>
    </servlet-mapping>
    <session-config>
        <session-timeout>
            30
        </session-timeout>
    </session-config>
    <welcome-file-list>
        <welcome-file>index.xhtml</welcome-file>
    </welcome-file-list>
</web-app>
```

## Prime Faces
Existe uma biblioteca com componentes já estilizados, cujo objetivo é facilitar o desenvolvimento das interfaces e já ter alguns componentes prontos para uso. Vamos usá-lo no projeto e fazer um formulário idêntico ao anterior, porém, usando Prime Faces.  
Para começar, precisamos adicionar essa dependência no projeto. Para isso, vamos incluir a dependência no pom.xml.  
**pom.xml**  
```xml
<dependency>
        <groupId>org.primefaces</groupId>
        <artifactId>primefaces</artifactId>
        <version>10.0.0</version>
</dependency>
```

E então, criar o formulário usando as Prime Faces:  
**index.xhtml**  
```html
<h:form>
    <p:panelGrid columns="2">
        <p:outputLabel value="Entrada" for="txtEntrada2" />
        <p:inputText value="#{controleAjax.entrada}" id="txtEntrada2" />
        <p:outputLabel value="Saida" for="txtSaida2" />
        <p:inputText value="#{controleAjax.saida}" id="txtSaida2" />
        <p:commandButton value="Processar" id="btnProcessar"
                            actionListener="#{controleAjax.processar()}" 
                            process="txtEntrada2 @this" 
                            update="txtSaida2" 
        />
    </p:panelGrid>
</h:form>
```

## Exercício
"Após processar os dados, como podemos fazer para remover o texto de entrada?"  
Para resolver isso, basta adicionar na função processar do controle o ``this.entrada = "";`` e incluir os campos de entrada dos dois formulários para a atualização (seja Prime Faces ou JSF):
````html
<?xml version='1.0' encoding='UTF-8' ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
      xmlns:h="http://xmlns.jcp.org/jsf/html"
      xmlns:f="http://xmlns.jcp.org/jsf/core"
          
      xmlns:p="http://primefaces.org/ui">
    <h:head>
        <title>Usando Ajax com JSF</title>
    </h:head>
    <h:body>
        <h:form>
            <h:panelGrid columns="2">
                <h:outputLabel value="Entrada" for="txtEntrada" />
                <h:inputText value="#{controleAjax.entrada}" id="txtEntrada" />
                <h:outputLabel value="Saída" for="txtSaida" />
                <h:inputText value="#{controleAjax.saida}" id="txtSaida" />
                <h:commandButton value="Processar" actionListener="#{controleAjax.processar()}">
                    <f:ajax render="txtSaida txtEntrada" execute="txtEntrada" />
                </h:commandButton>
            </h:panelGrid>
        </h:form>
        
        <h:form>
            <p:panelGrid columns="2">
                <p:outputLabel value="Entrada" for="txtEntrada2" />
                <p:inputText value="#{controleAjax.entrada}" id="txtEntrada2" />
                <p:outputLabel value="Saida" for="txtSaida2" />
                <p:inputText value="#{controleAjax.saida}" id="txtSaida2" />
                <p:commandButton value="Processar" id="btnProcessar"
                                 actionListener="#{controleAjax.processar()}" 
                                 process="txtEntrada2 @this" 
                                 update="txtSaida2 txtEntrada2" 
                />
            </p:panelGrid>
        </h:form>
    </h:body>
</html>
```