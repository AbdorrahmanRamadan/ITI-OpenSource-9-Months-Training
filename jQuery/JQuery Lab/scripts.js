$(() => {
    let foodTotal=parseFloat($('.cart-total').html()),VAT,Total,delivery,discount;

    const items = [
        { title: 'Share Box', price: 130, image: 'images/sharebox.jpg' },
        { title: 'Big Mac', price: 65, image: 'images/bigmac.jpg' },
        { title: 'Mix 2 Meal', price: 59, image: 'images/mix2meal.jpg' },
        { title: 'Big Tasty', price: 107.5, image: 'images/bigtasty.jpg' },
        { title: 'McFries', price: 27.5, image: 'images/mcfries.jpg' },
    ]
    for(let item of items) {
        const newItem = $('.item.hidden').clone();
        newItem
            .removeClass('hidden')
            .appendTo('.inner-list.menu')
            .children('.title')
            .html(`${item.title}`)
        newItem
            .children('.price')
            .html(`${item.price}`)

        newItem
            .children('.image').attr('src', item.image)
    }
    const addToCartTotal = (price) => {
        discount=0;
        foodTotal += parseFloat(price);
        VAT=parseFloat((foodTotal/100*14).toFixed(2));
        delivery= foodTotal?20:0;
        if((foodTotal)>300){
            discount=30;
            $('.discount.hidden').removeClass('hidden');
        }else {
            $('.discount').addClass('hidden');
        }
        Total=(foodTotal+delivery+VAT-discount).toFixed(2);
        $('.food-total').html(foodTotal);
        $('.VAT').html(VAT);
        $('.delivery').html(delivery);
        $('.cart-total').html(Total);
    }
    addToCartTotal(0)
    $(".item").draggable({
        helper: function() {
            return $(this).clone().appendTo(".order").css({
                "zIndex": 5
            }).show();
        },
        cursor: "move",
        containment: "document"
    }).droppable({
        accept: ".item.added",
        drop: function(event, ui) {
            if (!ui.draggable.hasClass("dropped"))
                $(ui.draggable).remove();
            addToCartTotal('-'+($(ui.draggable).children('.price').html()))
        }
    });

    $(".order").droppable({
        accept: ".item.menu",
        drop: function(event, ui) {
            if (!ui.draggable.hasClass("dropped"))
                dropped= $(ui.draggable).clone();
                dropped.removeClass("menu");
                dropped.addClass("added");
                $(this).append(dropped);
                addToCartTotal($(ui.draggable).children('.price').html())
        }
    }).sortable({
        cursor: "move",
        helper: function (evt, ui) {
            return $(ui).clone().appendTo(".order").show();
        }
    }).draggable({
        helper: function() {
            return $(this);
        },
    })
})
