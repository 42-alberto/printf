
#include "../includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/* --- INFRAESTRUCTURA PARA SIMULAR FALLOS --- */
int trigger_limit = -1;
int current_writes = 0;

// El write que usará el sistema al final
ssize_t	__real_write(int fd, const void *buf, size_t count);

// El wrap que intercepta las llamadas
ssize_t	__wrap_write(int fd, const void *buf, size_t count)
{
	current_writes++;
	if (trigger_limit != -1 && current_writes >= trigger_limit)
		return (-1);
	return __real_write(fd, buf, count);
}
/* ------------------------------------------- */

int	main(void)
{
	int ft, std;
	char *s_null = NULL;

	printf("--- TESTS GENERAL DE FORMATOS ---\n");
    ft = ft_printf("FT : [%010c] [%.3s] [%+d] [%#x]\n", 'A', "42cursus", 42, 255);
    std = printf("STD: [%010c] [%.3s] [%+d] [%#x]\n", 'A', "42cursus", 42, 255);
    printf("R: FT %d | STD %d\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("1. Chars y Strings\n");
	ft = ft_printf("FT : [%0++ - -#010c] [%0++ - -#010.3s] [%0++ - -#010s]	[%0++ - -#010.5s]\n", 'A', "42cursus", s_null, s_null);
	std = printf("STD: [%0++ - -#010c] [%0++ - -#010.3s] [%0++ - -#010s]	[%0++ - -#010.5s]\n", 'A', "42cursus", s_null, s_null);
	printf("R: FT %d | STD %d\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("2. Enteros\n");
	ft = ft_printf("FT : [%#0+10.5d] [%#0 010d] [%#0-10.5i]\n", 42, 42, -42);
	std = printf("STD: [%#0+10.5d] [%#0 010d] [%#0-10.5i]\n", 42, 42, -42);
	printf("R: FT %d | STD %d\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("3. Hexadecimales\n");
	ft = ft_printf("FT : [%0++ - -#0x] [%-#10X] [%-.0x]\n", 255, 255, 0);
	std = printf("STD: [%0++ - -#0x] [%-#10X] [%-.0x]\n", 255, 255, 0);
	printf("R: FT %d | STD %d\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("4. Punteros\n");
	int n = 42;
	ft = ft_printf("FT : [%0  #020p] [%+p] [%p] [%#+- 10.4p]\n",
			(void *)&n, (void *)&n, (void *)0, (void *)0);
	std = printf("STD: [%0  #020p] [%+p] [%p] [%#+- 10.4p]\n",
			(void *)&n, (void *)&n, (void *)0, (void *)0);
	printf("R: FT %d | STD %d\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("5. El símbolo %%\n");
	// Mi función gestiona el with en el doble %% 
	// tengo que probar como funciona en los ordenadores de 42
	ft = ft_printf("FT : [%%] [%-5%]\n");
	std = printf("STD: [%%] [%-5%]\n");
	printf("R: FT %d | STD %d)\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("6. Límites\n");
	ft = ft_printf("FT : [%u] [%u] [%d]\n", 0, UINT_MAX, INT_MIN);
	std = printf("STD: [%u] [%u] [%d]\n", 0, UINT_MAX, INT_MIN);
	printf("R: FT %d | STD %d\n", ft, std);
	if (ft == std)
		printf("RESULTADO: ✅\n\n");
	else
		printf("RESULTADO: ❌ difieren %d caracteres.\n\n", ft - std);

	ft_printf("--- TEST DE ROBUSTEZ (Fallo en write #10) ---\n");
	current_writes = 0;

	/*Tipo c*/
	trigger_limit = 10;
	ft = ft_printf("character%c", 'a');
	trigger_limit = -1;
	if (ft == -1)
		printf("\n✅ RESULTADO character: Detectó el fallo y devolvió %d.\n\n", ft);
	else
		printf("\n❌ ERROR: Retornó %d en lugar de -1. Revisa la captura de errores.\n\n", ft);
	

	/*Tipo s*/
	trigger_limit = 10;
	ft = ft_printf("String789%s", "Diez");
	trigger_limit = -1;
	if (ft == -1)
		printf("\n✅ RESULTADO String: Detectó el fallo y devolvió %d.\n\n", ft);
	else
		printf("\n❌ ERROR: Retornó %d en lugar de -1. Revisa la captura de errores.\n\n", ft);
	

	/*Decimales*/
	trigger_limit = 10;
	ft = ft_printf("Decimal%d", 8910);
	trigger_limit = -1;
	if (ft == -1)
		printf("\n✅ RESULTADO Decimal: Detectó el fallo y devolvió %d.\n\n", ft);
	else
		printf("\n❌ ERROR: Retornó %d en lugar de -1. Revisa la captura de errores.\n\n", ft);
	

	/*Hexadecimales*/
	trigger_limit = 10;
	ft = ft_printf("Hexadec%x", 89101112);
	trigger_limit = -1;
	if (ft == -1)
		printf("\n✅ RESULTADO Hexadecimal: Detectó el fallo y devolvió %d.\n\n", ft);
	else
		printf("\n❌ ERROR: Retornó %d en lugar de -1. Revisa la captura de errores.\n\n", ft);

	return (0);
}
