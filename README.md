# PDE_solver_demo

 $$accum_new = accum + grad * grad$$ $$linear += grad + (accum_{new}^{-lr_{power}} - accum^{-lr_{power}} / lr * var$$ $$quadratic = 1.0 / (accum_{new}^{lr_{power}} * lr) + 2 * l2$$ $$var = (sign(linear) * l1 - linear) / quadratic\ if\ |linear| > l1\ else\ 0.0$$ $$accum = accum_{new}$$
