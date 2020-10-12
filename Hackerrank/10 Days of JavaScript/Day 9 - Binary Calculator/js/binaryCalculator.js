/* Adapted from code by @eloyekunle - thanks! */

let btns = document.getElementsByTagName('button');
for (let btn of btns) {
    button.onclick = click;
}

function click(e) {
    var btn = e.target || e.srcElement;
    var action = document.getElementById(btn.id).innerHTML;
    var res = document.getElementById('res');
    
    switch (action) {
        case '0':
        case '1':
        case '+':
        case '-':
        case '*':
        case '/':
            res.innerHTML += action;
            break;
        case 'C':
            res.innerHTML = '';
            break;
        case '=':
            /* Parse binary numbers from res;
             * replace with decimal equivalents */
            var expr = res.innerHTML;
            var nums = /(\d+)/g;
            expr = expr.replace(nums, function(match) {
                return parseInt(match, 2);
            })

            /* Evaluate res and convert back to binary */
            res.innerHTML = eval(expr).toString(2);
            break;
    }
}
