import facebook

ACCESS_TOKEN = 'EAAG...'
graph = facebook.GraphAPI(access_token=ACCESS_TOKEN, version="16.0")

# Lấy posts
posts = graph.get_connections(id='your_page_id', connection_name='posts',
                              fields='message,created_time,permalink_url', limit=10)

for post in posts['data']:
    print(post['id'], post['created_time'], post.get('message'))