*This project has been created as part of the 42 curriculum by hvaini-d, joaopedr.*

# push_swap

## Descrição

O `push_swap` recebe uma lista de inteiros e imprime na saída padrão a menor
sequência de operações que ordena essa lista, usando duas pilhas (`a` e `b`) e
um conjunto restrito de instruções (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`).

O objetivo do projeto não é apenas ordenar: é escolher *qual* algoritmo usar.
O binário embute quatro estratégias distintas — uma O(n²), uma O(n√n), uma
O(n log n) e uma adaptativa que seleciona entre elas em tempo de execução a
partir de uma métrica de desordem calculada antes de qualquer movimento.

Todas as complexidades declaradas neste documento se referem ao **número de
operações Push_swap geradas**, não ao custo do algoritmo em C.

---

## Instruções

### Compilação

```sh
make          # gera ./push_swap
make bonus    # gera ./checker
make clean    # remove os objetos
make fclean   # remove objetos e binários
make re       # fclean + make
```

Compilado com `cc -Wall -Wextra -Werror`. A `libft` é compilada pelo seu
próprio Makefile antes do projeto.

### Uso

```sh
./push_swap 3 2 1
```

Cada operação é impressa em uma linha própria. Sem argumentos, o programa não
imprime nada e devolve o prompt. Se a pilha já estiver ordenada, nenhuma
operação é gerada.

### Flags

| Flag | Efeito |
| --- | --- |
| `--simple` | força a estratégia O(n²) |
| `--medium` | força a estratégia O(n√n) |
| `--complex` | força a estratégia O(n log n) |
| `--adaptive` | força a estratégia adaptativa (padrão) |
| `--bench` | imprime métricas no **stderr** (não interfere na saída de operações) |

As flags podem ser combinadas e vêm antes dos números:

```sh
./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt | ./checker 4 67 3 87 23
```

```
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n sqrt n)
[bench] total_ops:  9
[bench] sa: 0  sb: 0  ss: 0  pa: 2  pb: 2  ra: 4  rb: 0  rr: 0  rra: 1  rrb: 0  rrr: 0
```

### Erros

Imprime `Error` seguido de `\n` no **stderr** e retorna 1 para: argumentos não
numéricos, valores fora do intervalo de `int`, duplicatas, strings vazias e
flags desconhecidas.

---

## Estrutura do projeto

```
main.c                      leitura, validação e dispatch
push_swap.h
utils/parser/               validação de argumentos e construção da pilha
utils/lexer/                parsing das flags (bitmask) e resolução da estratégia
utils/stack/                pilha circular duplamente ligada, normalização por rank
utils/sorting_operations/   as 11 operações primitivas
utils/disorder/             cálculo da métrica de desordem
utils/error_handeling/
sorting/                    as quatro estratégias e seus utilitários
benchmark/                  saída do modo --bench
bonus/                      checker
libft/
```

### Decisão de projeto: ordenar por *rank*, não por valor

Depois do parsing, `normalize_stack()` atribui a cada nó um `rank` de `0` a
`n-1` correspondente à sua posição na ordem final. **Todos os algoritmos
operam sobre o rank, nunca sobre o valor.**

Isso importa por dois motivos:

1. Torna o radix sort possível. Ordenar inteiros arbitrários por bits exigiria
   32 passadas e lidar com sinal; ordenar ranks exige apenas `⌈log₂ n⌉`
   passadas (9 para n = 500).
2. Elimina qualquer preocupação com overflow durante as comparações internas.

O custo é uma passada O(n²) na normalização, mas em tempo de C — ela não gera
nenhuma operação.

---

## A métrica de desordem

A desordem é a fração de pares invertidos da pilha inicial:

```
disorder = pares_invertidos / total_de_pares,  total_de_pares = n(n-1)/2
```

`0.0` = já ordenada, `1.0` = invertida, `~0.5` = aleatória. É calculada em
`utils/disorder/disorder.c` **antes de qualquer movimento**, como exige o
subject.

---

## As quatro estratégias

### 1. Simple — O(n²) — `sorting/simple.c`

Selection sort adaptado. Repetidamente localiza o menor elemento de `a`, gira
até ele pelo lado mais barato e faz `pb`; ao final devolve tudo com `pa`.

Cada uma das n extrações custa até n/2 rotações, logo **O(n²) operações**.

Para `n ≤ 5` o dispatch usa `super_small_sort` (`sorting/super_small.c`), que
empurra os menores até restarem três e resolve o caso de três por comparação
direta. É um caso limitado por constante e não altera a classe assintótica.

### 2. Medium — O(n√n) — `sorting/lis.c`, `sorting/complex_merge.c`

Esta é a estratégia mais elaborada do projeto, em duas fases:

**Fase 1 — preservar a maior subsequência crescente (LIS).**
Uma DP O(n²) em C identifica a maior subsequência crescente dos ranks. Esses
elementos já estão em ordem relativa correta e permanecem em `a`; todos os
outros vão para `b`. Como não geramos operação para *decidir*, o custo dessa
fase é apenas o das rotações e pushes.

**Fase 2 — reinserção por custo mínimo.**
Enquanto `b` não estiver vazia, para cada elemento de `b` calculamos o custo
real de trazê-lo ao topo de `b` e simultaneamente girar `a` até sua posição de
inserção. Inserimos o mais barato. Repete-se até esvaziar `b`.

Duas otimizações importantes:

- **Rotações combinadas.** Quando `a` e `b` precisam girar no mesmo sentido,
  gastamos um único `rr` (ou `rrr`) em vez de duas operações separadas
  (`sorting/turn_both.c`). Isso reduziu ~18% das operações em n = 500.
- **O modelo de custo reflete a execução.** `move_cost()` devolve
  `max(custo_a, custo_b)` quando os sentidos coincidem e `custo_a + custo_b`
  quando divergem — exatamente o que `turn_both()` vai gastar. Pontuar os
  candidatos com o custo real, e não com a soma ingênua, faz o algoritmo
  escolher elementos diferentes e melhores.

**Justificativa da classe:** o limite superior é O(n√n). Em uma permutação
aleatória a LIS tem comprimento esperado ~2√n, então ~n − 2√n elementos são
reinseridos, cada um a custo O(√n) amortizado dado que `a` permanece ordenada
e as posições de inserção ficam distribuídas. Empiricamente `ops / (n·√n)`
*decresce* com n (0.585 em n = 50 → 0.422 em n = 1000), confirmando que
O(n√n) é um limite superior válido — não apertado.

### 3. Complex — O(n log n) — `sorting/complex.c`

Radix sort LSD binário sobre os ranks. Para cada bit, de 0 a `⌈log₂ n⌉ − 1`:
elementos com o bit ligado recebem `ra` e permanecem em `a`; os demais vão
para `b` com `pb`. Ao fim da passada, tudo volta com `pa`.

São `⌈log₂ n⌉` passadas, cada uma tocando os n elementos uma vez.
**O(n log n) operações**, com o custo decomposto exatamente em:

```
varredura      = n × bits        (cada elemento recebe ra ou pb, uma vez por passada)
reunificação   = 1 por elemento devolvido a `a`
```

Em n = 500 isso é `pb 2284 + ra 2216 = 4500 = 500 × 9` de varredura, mais
`pa 2284` de reunificação — total 6784. A constante medida é **1.512 ×
n·log₂n**, estável de n = 100 a n = 1000.

### 4. Adaptive — padrão — `utils/lexer/bitmask_resolve.c`

Seleciona a estratégia pela desordem medida, exatamente nos limiares que o
subject determina:

| desordem | estratégia | classe exigida |
| --- | --- | --- |
| `< 0.2` | Simple | O(n²) |
| `0.2 ≤ d < 0.5` | Medium | O(n√n) |
| `≥ 0.5` | Complex | O(n log n) |

**Racional dos limiares.** Eles não foram escolhidos por nós — são impostos
pelo subject (VI.3.3). Mas fazem sentido do ponto de vista do custo: com
desordem baixa há poucas inversões a corrigir e um método O(n²) faz pouquíssimo
trabalho real (uma pilha já ordenada custa zero operações, detectada por
`ft_is_sorted` antes do dispatch). Conforme a desordem cresce, o volume de
trabalho passa a justificar algoritmos com melhor comportamento assintótico.

A seção seguinte discute onde esse racional se descola da realidade medida.

---

## Análise de complexidade

### Tempo (em operações Push_swap geradas)

| Estratégia | Limite superior | Constante medida |
| --- | --- | --- |
| Simple | O(n²) | ~0.13 n² |
| Medium | O(n√n) | ~0.42–0.59 n√n (decrescente) |
| Complex | O(n log n) | 1.512 n·log₂n |

### Espaço

| Componente | Custo |
| --- | --- |
| Pilhas `a` e `b` | O(n) nós (lista circular duplamente ligada) |
| Simple | O(1) adicional |
| Medium | O(n) — vetores `ranks`, `dp`, `parent`, `in_lis` |
| Complex | O(n) — pilha `b` |
| Log de operações | O(número de operações) |

O log de operações é acumulado em uma string antes de ser impresso, o que o
torna o maior consumidor de memória em entradas grandes — O(n log n) caracteres
na estratégia complex. Emitir cada operação diretamente à medida que é aplicada
eliminaria esse custo; é a melhoria mais óbvia pendente no projeto.

---

## (Parêntese) Sobre a seleção do algoritmo e uma tensão no subject

Esta seção existe porque a parte mais interessante do projeto não foi
implementar os algoritmos, e sim descobrir que **as duas exigências do subject
— os limiares de desordem e as metas de performance — não são simultaneamente
satisfazíveis nos tamanhos avaliados.** Documentamos aqui o raciocínio e as
medições, porque a conclusão é uma escolha deliberada e não uma falha de
implementação.

### 1. Entrada aleatória cai exatamente em cima do limiar de 0.5

A desordem de uma permutação aleatória tem média 0.5. O desvio é pequeno e
diminui com n:

| n | faixa observada (40 execuções) | Medium | Complex |
| --- | --- | --- | --- |
| 100 | 41.03% – 58.40% | 20 | 20 |
| 500 | 46.88% – 53.89% | 19 | 21 |

Ou seja: o caso exatamente usado no benchmark — números aleatórios — fica em
cima da fronteira. Metade das execuções avaliadas vai para a estratégia
O(n√n), metade para a O(n log n). Não é uma escolha nossa; é consequência
matemática do limiar fixado.

### 2. Nos tamanhos avaliados, o algoritmo "melhor" é o mais lento

| n | Medium O(n√n) | Complex O(n log n) | diferença |
| --- | --- | --- | --- |
| 100 | 547 | 1084 | complex gasta **2× mais** |
| 500 | 5064 | 6784 | complex gasta **32% mais** |

O subject obriga o uso de O(n log n) para desordem ≥ 0.5, ou seja, obriga a
usar o algoritmo empiricamente pior justamente nas entradas que ele mede.

### 3. Onde as classes de fato se cruzam: n ≈ 1600

Medimos o ponto em que a vantagem assintótica finalmente aparece:

| n | Medium | Complex | vencedor |
| --- | --- | --- | --- |
| 500 | 5136 | 6784 | Medium por 32% |
| 1000 | 13134 | 15068 | Medium por 15% |
| 1500 | 24098 | 25336 | Medium por 5% |
| 1750 | 30473 | 29343 | **Complex** por 4% |
| 4000 | 99160 | 72272 | Complex por 37% |

A troca acontece por volta de **n = 1600** — mais de três vezes o maior
tamanho que o subject avalia (500). Abaixo disso, `√n` ainda é competitivo com
`log₂ n` multiplicado pelas constantes reais de cada método.

### 4. O piso da classe O(n log n) nesta máquina é ~1.5·n·log₂n

Poderia ser um defeito do nosso radix. Para verificar, simulamos três
algoritmos O(n log n) estruturalmente diferentes na mesma máquina de duas
pilhas:

| algoritmo | n=100 | n=200 | n=500 | n=1000 | constante |
| --- | --- | --- | --- | --- | --- |
| radix LSD (nosso) | 1084 | 2468 | 6784 | 15068 | **1.512** |
| radix MSD | 1118 | 2634 | 7440 | 16872 | 1.66–1.69 |
| quicksort (pivô mediana) | 1068 | 2538 | 7375 | 16761 | 1.61–1.68 |

Todos convergem para 1.5–1.7 × n·log₂n. Nenhum fica abaixo de 1.5. A constante
pertence à **máquina** (duas pilhas, este conjunto de operações), não ao radix.

Tentamos especificamente o **MSD**, que em um array eliminaria a reunificação —
depois de particionar, os dois grupos são independentes e a concatenação é
gratuita. **Em duas pilhas essa vantagem não existe:** a resposta precisa
terminar dentro da pilha `a`, então o grupo baixo, que está em `b`, tem que ser
fisicamente devolvido, um `pa` por elemento. Essa devolução *é* a reunificação.
Pior: o MSD ainda paga para reposicionar o grupo que fica quando há outros
segmentos abaixo dele, e por isso fica **3% a 12% mais caro** que o LSD, com a
diferença crescendo com n.

Heap sort e binary indexed tree, também sugeridos pelo subject, não são
expressáveis com eficiência aqui: um heap exige acesso indexado a posições
arbitrárias, e alcançar o elemento *i* custa *i* rotações; e uma BIT é uma
estrutura para calcular ranks — trabalho que `normalize_stack()` já faz de
graça em tempo de C.

### 5. Conclusão: "excellent" é inatingível no ramo obrigatório

Com o piso de 1.5·n·log₂n:

| n | piso da classe O(n log n) | meta "excellent" | resultado |
| --- | --- | --- | --- |
| 100 | 1050 | < 700 | inatingível |
| 500 | 6750 | < 5500 | inatingível |

Nossa estratégia Medium atinge as duas metas com folga (547 e 5064). Nossa
estratégia Complex está no ótimo da sua classe e ainda assim não as atinge.
Como metade das execuções aleatórias é roteada para Complex pelo limiar de 0.5,
metade dos resultados fica em "good" em vez de "excellent".

Optamos por **não** apontar o ramo de alta desordem para o código LIS/greedy,
apesar de ele ser mais rápido. O pior caso dele é O(n²) operações, e VI.3.1
exige que a classe declarada valha no modelo de operações. Declarar O(n log n)
para um algoritmo que não o é seria uma afirmação falsa sobre complexidade — o
oposto do que este projeto se propõe a ensinar.

---

## Resultados medidos

30 execuções por configuração, entrada aleatória, verificadas com o `checker`.

| Estratégia | n = 100 (média / pior) | n = 500 (média / pior) |
| --- | --- | --- |
| `--simple` | 1454 / 1622 | 32425 / 33901 |
| `--medium` | **547 / 590** | **5064 / 5372** |
| `--complex` | 1084 / 1084 | 6784 / 6784 |
| padrão (adaptive) | ~50% Medium, ~50% Complex | ~50% Medium, ~50% Complex |

Metas do subject: n = 100 → passa < 2000, bom < 1500, excelente < 700.
n = 500 → passa < 12000, bom < 8000, excelente < 5500.

O radix é determinístico no número de operações para um dado n, porque o
número de passadas e a distribuição de bits dos ranks não dependem da
permutação — daí média e pior caso coincidirem.

---

## Bônus: checker

```sh
make bonus
./push_swap 3 2 1 | ./checker 3 2 1     # OK
```

O `checker` recebe a mesma lista de inteiros, lê operações do stdin uma por
linha, executa-as e imprime `OK` se `a` terminar ordenada e `b` vazia, `KO`
caso contrário, e `Error` no stderr para operação inexistente ou argumentos
inválidos. Sem argumentos, não imprime nada.

Ele reutiliza o parser, a pilha e as operações primitivas do programa
principal — apenas o dispatch de operações e o laço de leitura são novos.

---

## Contribuições

<!-- PREENCHER: esta seção é exigida por VI.1 e pela Chapter IX. -->
<!-- Descrevam quem trabalhou em quê, de forma que dê para reconhecer a
     contribuição de cada um. Sugestão de estrutura: -->

**hvaini-d (Henrique Danielewicz)** — <!-- PREENCHER -->

**joaopedr (João Pedro Diniz)** — <!-- PREENCHER -->

---

## Recursos

- Donald Knuth, *The Art of Computer Programming, Vol. 3: Sorting and
  Searching* — radix sort LSD/MSD e análise de complexidade de ordenação.
- [Longest Increasing Subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)
  — a DP O(n²) usada na estratégia Medium.
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- Comprimento esperado da LIS em permutações aleatórias (~2√n) — resultado de
  Vershik–Kerov / Logan–Shepp, base do argumento de complexidade da Medium.
- `norminette` — verificação da Norm.
- `valgrind` — verificação de vazamentos.

### Uso de IA

