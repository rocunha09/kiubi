/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// int main(void)
// {
//     int *colors;
//     int *colors_result;

//     colors = create_color_rgb(3);

//     colors[0] = 100;
//     colors[1] = 120;
//     colors[2] = 255;    

//     getchar();

//     if (colors != NULL)
//     {
//         printf("%d ", colors[0]);
//         printf("%d ", colors[1]);
//         printf("%d \n", colors[2]);
//     }
//     else
//     {
//         printf("NULL\n");
//     }

//     getchar();

//     set_floor_color_rgb(colors);

//     getchar();

//     colors_result = get_floor_color_rgb();
//     if (colors_result != NULL)
//     {
//         printf("%d ", colors_result[0]);
//         printf("%d ", colors_result[1]);
//         printf("%d \n", colors_result[2]);
//     }
//     else
//     {
//         printf("%ls\n", get_floor_color_rgb());
//     }

//     getchar();

//     destroy_color_rgb("floor");

//     getchar();
//     return 0;
// }

int main(void)
{
    int *colors;
    //use para alocar
    colors = create_color_rgb(3);
    
    //atribuindo antes de passar... apenas exemplo
    colors[0] = 120;
    colors[1] = 180;
    colors[2] = 255; 

    //use para setar [255,255,255] conforme solicitou
    set_ceiling_color_rgb(colors);
    //ou floor
    set_floor_color_rgb(colors);
}

int main(void)
{
    int *colors;
    int *colors_result;

    colors = create_color_rgb(3);

    colors[0] = 120;
    colors[1] = 180;
    colors[2] = 255;    

    getchar();

    if (colors != NULL)
    {
        printf("%d ", colors[0]);
        printf("%d ", colors[1]);
        printf("%d \n", colors[2]);
    }
    else
    {
        printf("NULL\n");
    }

    getchar();

    set_ceiling_color_rgb(colors);

    getchar();

    colors_result = get_ceiling_color_rgb();
    if (colors_result != NULL)
    {
        printf("%d ", colors_result[0]);
        printf("%d ", colors_result[1]);
        printf("%d \n", colors_result[2]);
    }
    else
    {
        printf("%ls\n", get_ceiling_color_rgb());
    }

    getchar();

    destroy_color_rgb("ceiling");

    getchar();
    return 0;
}
