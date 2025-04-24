CREATE TABLE IF NOT EXISTS registros ( 
    id INT (11) AUTO_INCREMENT PRIMARY KEY NOT NULL,
    nome VARCHAR (255) UNIQUE NOT NULL,
    ano_de_lancamento INT (11),
    temporadas INT (11),
    episodios INT (11),
    elenco_principal VARCHAR(255),
    personagens_principais VARCHAR(255),
    servico_de_streaming VARCHAR(255),
    nota DECIMAL(11,2)
);