-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 20/06/2023 às 21:41
-- Versão do servidor: 10.4.28-MariaDB
-- Versão do PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `frutaria`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `fornecedor`
--

CREATE TABLE `fornecedor` (
  `id_fornecedor` int(5) NOT NULL,
  `nome_fornecedor` varchar(50) DEFAULT NULL,
  `site` varchar(150) DEFAULT NULL,
  `telefone` varchar(11) DEFAULT NULL,
  `uf` varchar(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `fornecedor`
--

INSERT INTO `fornecedor` (`id_fornecedor`, `nome_fornecedor`, `site`, `telefone`, `uf`) VALUES
(1, 'MariaFrutas', 'mariafrutas.com', '61951515478', 'DF'),
(2, 'JoãoFrutas', 'joaofrutas.com', '61923456789', 'DF'),
(3, 'AndréFrutas', 'andrefrutas.com', '31978901234', 'MG'),
(4, 'LauraFrutas', 'laurafrutas.com', '31967890123', 'MG'),
(5, 'SofiaFrutas', 'sofiafrutas.com', '21945678901', 'RJ'),
(6, 'CarlosFrutas', 'carlosfrutas.com', '21956789012', 'RJ'),
(7, 'GuilhermeFrutas', 'guilhermefrutas.com', '61987654321', 'RS'),
(8, 'BeatrizFrutas', 'beatrizfrutas.com', '51989012345', 'RS'),
(9, 'PedroFrutas', 'pedrofrutas.com', '11951515478', 'SP'),
(10, 'AnaFrutas', 'anafrutas.com', '11934567890', 'SP');

-- --------------------------------------------------------

--
-- Estrutura para tabela `produto`
--

CREATE TABLE `produto` (
  `id_produto` int(5) NOT NULL,
  `nome_produto` varchar(50) DEFAULT NULL,
  `valor_compra` float DEFAULT NULL,
  `valor_venda` float DEFAULT NULL,
  `valor_lucro` int(6) DEFAULT NULL,
  `perc_lucro` int(3) DEFAULT NULL,
  `id_fornecedor` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `produto`
--

INSERT INTO `produto` (`id_produto`, `nome_produto`, `valor_compra`, `valor_venda`, `valor_lucro`, `perc_lucro`, `id_fornecedor`) VALUES
(1, 'Kiwi', 6, 13, 7, 54, 1),
(2, 'Laranja', 2, 5, 3, 60, 1),
(3, 'Laranja', 3, 5, 2, 40, 2),
(4, 'Maça', 3, 8, 5, 63, 2),
(5, 'Abacaxi', 11, 23, 12, 52, 3),
(6, 'Uva', 8, 19, 11, 58, 3),
(7, 'Pera', 6, 17, 11, 65, 4),
(8, 'Uva', 9, 19, 10, 53, 4),
(9, 'Banana', 2, 4, 2, 50, 5),
(10, 'Melancia', 12, 29, 17, 59, 5),
(11, 'Banana', 4, 13, 9, 69, 6),
(12, 'Morango', 5, 15, 10, 67, 6),
(13, 'Kiwi', 5, 11, 6, 55, 7),
(14, 'Manga', 4, 11, 7, 64, 7),
(15, 'Manga', 4, 16, 12, 75, 8),
(16, 'Melancia', 13, 27, 14, 52, 8),
(17, 'Limão', 3, 7, 4, 57, 9),
(18, 'Pera', 3, 10, 7, 70, 9),
(19, 'Limão', 2, 7, 5, 71, 10),
(20, 'Melão', 6, 11, 5, 45, 10);

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `fornecedor`
--
ALTER TABLE `fornecedor`
  ADD PRIMARY KEY (`id_fornecedor`);

--
-- Índices de tabela `produto`
--
ALTER TABLE `produto`
  ADD PRIMARY KEY (`id_produto`),
  ADD KEY `id_fornecedor` (`id_fornecedor`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `fornecedor`
--
ALTER TABLE `fornecedor`
  MODIFY `id_fornecedor` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT de tabela `produto`
--
ALTER TABLE `produto`
  MODIFY `id_produto` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- Restrições para tabelas despejadas
--

--
-- Restrições para tabelas `produto`
--
ALTER TABLE `produto`
  ADD CONSTRAINT `produto_ibfk_1` FOREIGN KEY (`id_fornecedor`) REFERENCES `fornecedor` (`id_fornecedor`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
