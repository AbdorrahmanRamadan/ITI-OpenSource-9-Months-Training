from django.urls import path
from .views import todo_home, task_details, delete_task, mark_as_done, edit_task, update_task, create_task,save_new_task
app_name = 'todo'
urlpatterns = [
    path('home', todo_home, name="home"),
    path('details/<str:task_id>', task_details, name="task_details"),
    path('delete/<str:task_id>', delete_task, name="task_deleted"),
    path('done/<str:task_id>', mark_as_done, name="task_status"),
    path('edit/<str:task_id>', edit_task, name="edit_task"),
    path('update', update_task, name="task_updated"),
    path('create', create_task, name="new_task"),
    path('save', save_new_task, name="new_task_added"),
]