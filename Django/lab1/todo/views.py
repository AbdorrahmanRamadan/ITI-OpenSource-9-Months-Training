from django.shortcuts import render, HttpResponse, redirect, reverse
from django import forms

todoList = {
    '1': {
        'id': 1,
        'name': 'breakfast',
        'priority': 2,
        'is_done': False
    },
    '2': {
        'id': 2,
        'name': 'study',
        'priority': 1,
        'is_done': True
    },
    '3': {
        'id': 3,
        'name': 'clean room',
        'priority': 3,
        'is_done': False
    },
    '4': {
        'id': 4,
        'name': 'go to gym',
        'priority': 4,
        'is_done': False
    }
}


# Create your views here.
def todo_home(request):
    return render(request, 'todo/todo.html', context={'todo_list': todoList})


def task_details(request, **kwargs):
    task_id = kwargs.get('task_id')
    task = todoList.get(task_id)
    return render(request, "todo/details.html", context={'task_details': task})


def delete_task(request, **kwargs):
    task_id = kwargs.get('task_id')
    todoList.pop(task_id)
    return redirect(reverse("todo:home"))


def mark_as_done(request, **kwargs):
    task_id = kwargs.get('task_id')
    task = todoList.get(task_id)
    task['is_done'] = True
    return redirect(reverse("todo:home"))


def edit_task(request, **kwargs):
    task_id = kwargs.get('task_id')
    task = todoList.get(task_id)
    return render(request, "todo/edit.html", context={'task_details': task, 'task_id': task_id})


def update_task(request):
    task_id = request.POST.get('task_id')
    task = todoList.get(task_id)
    task['name'] = request.POST.get('task_name')
    task['priority'] = request.POST.get('task_prior')
    if request.POST.get('task_status') == "True":
        task['is_done'] = True
    else:
        task['is_done'] = False
    return redirect(reverse("todo:home"))


def create_task(request):
    return render(request, "todo/add.html")


def save_new_task(request):
    task_id = request.POST.get('task_id')
    todoList[task_id] = {
        'name': request.POST.get('task_name'),
        'priority': request.POST.get('task_prior'),
    }
    task = todoList.get(task_id)
    if request.POST.get('task_status') == "True":
        task['is_done'] = True
    else:
        task['is_done'] = False
    return redirect(reverse("todo:home"))
