recursos:
https://es.wikipedia.org/wiki/An%C3%A1lisis_de_algoritmos
https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

analisis del problema para ver la soluci'on que usar.
2 videos de youtube 
https://web.archive.org/web/20220802162832/https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/#sorting_algorithm_for_3_numbers

info sobre los algoritmos
https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0


🔹 La estructura general del método que estás usando
	1.	Asignas index (rango ordenado).
	2.	Empujas todo menos 3 a B.
	3.	Ordenas 3 en A.
	4.	Para cada nodo en B:
	•	calculas target_pos en A
	•	calculas cost_a
	•	calculas cost_b
	5.	Eliges el nodo con menor coste total.
	6.	Ejecutas movimientos combinados si es posible.
	7.	Haces pa.
	8.	Repetir.
	9.	Rotar A final para que el mínimo quede arriba.

Eso es exactamente el llamado “Turkish”.