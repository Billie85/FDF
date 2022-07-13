/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:01:48 by root              #+#    #+#             */
/*   Updated: 2022/07/13 23:50:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* こちらの方の考え方を参考にしていきます。↓
------------------------------------------- How to do -------------------------------------------
**	1. read file
**		- get height(how many lines) of text
**		- get width(how many numbers in line)　　　←ここまで完璧、size_tでやってる。

**		- allocate memory for **int by using width and height (look your ft_strsplit() )
**		- read file and write number into **int matrix
**				by using ft_strsplit() and atoi()
**	--------------
**	2. drawing line function (google Bresenham algorithm)
**		- find by how much we need to increase x and by how much we need to increase y
**			by using float. Example:
**				x = 2; x1 = 4;
**				y = 2; y1 = 6;
**				steps for x: 2
**				steps for y: 4
**				that means that y should grow 2 times faster than x
**				ewery loop step: y += 1 and x += 0.5
**				after 4 steps x and y will be equal with x1, y1
**
**					real x:y		x:y     pixels				
**			start:		2.0 : 2.0		2:2        .
**			step1:		2.5 : 3.0		2:3        .
**			step2:		3.0 : 4.0		3:4         .
**			step3:		3.5 : 5.0		3:5         .
**			step4:		4.0 : 6.0		4:6          .
**
**				that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
**	--------------
**	3. function which draws lines beetwen every dot
**		- examle:
**				0->		0->		0->		0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		0->		0->		0
**			'->' and '|'are lines between dots 
**			every dot has two lines (right and down):	0->
**                                                                      |
**	----------------
**	4. adding 3D
**		- change coordinates by using isometric formulas:
**			x` = (x - y) * cos(angle)
**			y` = (x + y) * sin(angle) - z
**		- x` and y` are coordintes in 3D format (default angle 0.8)
**	----------------
**	5. adding donuses (move, rotation, zoom)
**		- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
**			call the func. deal_key.
**		- In the deal key func. you have to change some parametrs, clear the window with
**			mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
**	----------------
**	6. error handling
**		- check if argc == 2
**		- check if file exists: if ((fd = open(file_name, O_RDONLY) > 0))
**	----------------
**	7. fix leaks
**		- type leaks a.out or leaks fdf in your shell */




//----memo----
//最初にファイルを読み込む必要がある、
//読み込んだファイルから、縦横のマップの作成を始める。
//色も入ってくるから、，で区切る必要がある。
//基本的にスペースと，でく区切る。
//メインの部分である、2次元配列　[0][0] [0][1] [0][2] を作る、
//読み込んだファイルの中身は基本的にすべて、z軸だと思ってOK
//2次元配列で計算をして、色々作って、そこにファイルを持ってきて、
//その持ってきたtest.txtはz軸になってるから　メインの部分で位置を照らし合わせて、組み合わせていく。
//マップを読み込む作業は終わったから、今度はlineを書いていくよ
