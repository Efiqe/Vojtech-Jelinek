Popište, jakým způsobem chápete Dependency Inversion Principle. Uveďte vlastní příklad, na kterém to vysvětlete.
  Znamená to, že moduly vyšší třídy nemaj záležet na modulech nižší třídy. 
  Například: 
    Máme formulář s buttoneml. Když na button klikneme vznikně nějaký event. Tento event nám vytvoří novou instanci nějakého objektu. 
    A zavolá nějakou jeho metodu. Ta například vytvoří další instanci nějakého objektu a zavoláme nějakou metodu tohoto objektu. 
    Tato metoda nám třeba zapíše nějaké data co byli v tom formuláři do databáze.
